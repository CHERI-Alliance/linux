// SPDX-License-Identifier: GPL-2.0

#include <linux/console.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_platform.h>
#include <linux/serial.h>
#include <linux/serial_core.h>
#include <linux/slab.h>
#include <linux/timer.h>
#include <linux/tty_flip.h>
#include <linux/platform_device.h>

#define OFF_TX 0
#define OFF_TRACE 4

struct sailuart_port {
	struct uart_port port;
	u32 id;
};

#define to_sailuart_port(port)	container_of(port, struct sailuart_port, port)

struct sailuart_port sailuart_ports[1];

#ifdef CONFIG_SERIAL_SAILUART_CONSOLE
static struct console sailuart_console;
#endif

static struct uart_driver sailuart_driver = {
	.owner = THIS_MODULE,
	.driver_name = "sailuart",
	.dev_name = "ttySXU",
	.major = 0,
	.minor = 0,
	.nr = 1,
#ifdef CONFIG_SERIAL_SAILUART_CONSOLE
	.cons = &sailuart_console,
#endif
};

static void sailuart_putchar(struct uart_port *port, unsigned char ch)
{
	writel(ch, port->membase + OFF_TX);
}

static unsigned int sailuart_tx_empty(struct uart_port *port)
{
	return TIOCSER_TEMT;
}

static void sailuart_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
	/* modem control register is not present in SailUART */
}

static unsigned int sailuart_get_mctrl(struct uart_port *port)
{
	return TIOCM_CTS | TIOCM_DSR | TIOCM_CAR;
}

static void sailuart_stop_tx(struct uart_port *port)
{
}

static void sailuart_start_tx(struct uart_port *port)
{
	u8 ch;

	uart_port_tx(port, ch, true, sailuart_putchar(port, ch));
}

static void sailuart_stop_rx(struct uart_port *port)
{
}

static void sailuart_break_ctl(struct uart_port *port, int break_state)
{
	/* Sailuart doesn't support sending break signal */
}

static int sailuart_startup(struct uart_port *port)
{
	return 0;
}

static void sailuart_shutdown(struct uart_port *port)
{
}

static void sailuart_set_termios(struct uart_port *port, struct ktermios *new,
				 const struct ktermios *old)
{
	unsigned int baud;
	unsigned long flags;

	uart_port_lock_irqsave(port, &flags);

	/* update baudrate */
	baud = uart_get_baud_rate(port, new, old, 0, 460800);
	uart_update_timeout(port, new->c_cflag, baud);

	uart_port_unlock_irqrestore(port, flags);
}

static const char *sailuart_type(struct uart_port *port)
{
	return "sailuart";
}

static void sailuart_release_port(struct uart_port *port)
{
}

static int sailuart_request_port(struct uart_port *port)
{
	return 0;
}

static void sailuart_config_port(struct uart_port *port, int flags)
{
	/*
	 * Driver core for serial ports forces a non-zero value for port type.
	 * Write an arbitrary value here to accommodate the serial core driver,
	 * as ID part of UAPI is redundant.
	 */
	port->type = 1;
}

static int sailuart_verify_port(struct uart_port *port,
				struct serial_struct *ser)
{
	if (port->type != PORT_UNKNOWN && ser->type != 1)
		return -EINVAL;

	return 0;
}

static const struct uart_ops sailuart_ops = {
	.tx_empty	= sailuart_tx_empty,
	.set_mctrl	= sailuart_set_mctrl,
	.get_mctrl	= sailuart_get_mctrl,
	.stop_tx	= sailuart_stop_tx,
	.start_tx	= sailuart_start_tx,
	.stop_rx	= sailuart_stop_rx,
	.break_ctl	= sailuart_break_ctl,
	.startup	= sailuart_startup,
	.shutdown	= sailuart_shutdown,
	.set_termios	= sailuart_set_termios,
	.type		= sailuart_type,
	.release_port	= sailuart_release_port,
	.request_port	= sailuart_request_port,
	.config_port	= sailuart_config_port,
	.verify_port	= sailuart_verify_port,
};

static int sailuart_probe(struct platform_device *pdev)
{
	struct sailuart_port *uart;
	struct uart_port *port;
	int dev_id, ret;

	dev_id = 0;

#if 0
	uart = devm_kzalloc(&pdev->dev, sizeof(struct sailuart_port), GFP_KERNEL);
	if (!uart)
		return -ENOMEM;
#else
	uart = &sailuart_ports[dev_id];
#endif

	uart->id = dev_id;
	port = &uart->port;

	/* get membase */
	if (!port->membase) {
		port->membase = devm_platform_get_and_ioremap_resource(pdev, 0, NULL);
		if (IS_ERR(port->membase)) {
			ret = PTR_ERR(port->membase);
			goto err_erase_id;
		}
	}

	/* values not from device tree */
	port->dev = &pdev->dev;
	port->iotype = UPIO_MEM;
	port->flags = UPF_BOOT_AUTOCONF;
	port->ops = &sailuart_ops;
	port->regshift = 2;
	port->fifosize = 16;
	port->iobase = 1;
	port->type = PORT_UNKNOWN;
	port->line = dev_id;

	platform_set_drvdata(pdev, port);

	ret = uart_add_one_port(&sailuart_driver, &uart->port);
	if (ret)
		goto err_erase_id;

	return 0;

err_erase_id:

	return ret;
}

static void sailuart_remove(struct platform_device *pdev)
{
	struct uart_port *port = platform_get_drvdata(pdev);

	uart_remove_one_port(&sailuart_driver, port);
}

static const struct of_device_id sailuart_of_match[] = {
	{ .compatible = "sail,sailuart" },
	{}
};
MODULE_DEVICE_TABLE(of, sailuart_of_match);

static struct platform_driver sailuart_platform_driver = {
	.probe = sailuart_probe,
	.remove = sailuart_remove,
	.driver = {
		.name = "sailuart",
		.of_match_table = sailuart_of_match,
	},
};

#ifdef CONFIG_SERIAL_SAILUART_CONSOLE

static void sailuart_console_write(struct console *co, const char *s,
	unsigned int count)
{
	struct sailuart_port *uart;
	struct uart_port *port;
	unsigned long flags;
	int locked = 1;

	if ((co->index < 0 || co->index >= ARRAY_SIZE(sailuart_ports)))
                return;

	uart = &sailuart_ports[co->index];
	port = &uart->port;

	if (oops_in_progress)
		locked = uart_port_trylock_irqsave(port, &flags);
	else
		uart_port_lock_irqsave(port, &flags);

	uart_console_write(port, s, count, sailuart_putchar);

	if (locked)
		uart_port_unlock_irqrestore(port, flags);
}

static int sailuart_console_setup(struct console *co, char *options)
{
	struct sailuart_port *uart;
	struct uart_port *port;
	int baud = 115200;
	int bits = 8;
	int parity = 'n';
	int flow = 'n';

	if ((co->index < 0 || co->index >= ARRAY_SIZE(sailuart_ports)))
                return -ENODEV;

	uart = &sailuart_ports[co->index];
	port = &uart->port;
	if (!port->membase)
		return -ENODEV;

	if (options)
		uart_parse_options(options, &baud, &parity, &bits, &flow);

	return uart_set_options(port, co, baud, parity, bits, flow);
}

static struct console sailuart_console = {
	.name = "ttySXU",
	.write = sailuart_console_write,
	.device = uart_console_device,
	.setup = sailuart_console_setup,
	.flags = CON_PRINTBUFFER,
	.index = -1,
	.data = &sailuart_driver,
};

static int __init sailuart_console_init(void)
{
	register_console(&sailuart_console);

	return 0;
}
console_initcall(sailuart_console_init);

static void early_sailuart_write(struct console *console, const char *s,
				    unsigned int count)
{
	struct earlycon_device *device = console->data;
	struct uart_port *port = &device->port;

	uart_console_write(port, s, count, sailuart_putchar);
}

static int __init early_sailuart_setup(struct earlycon_device *device,
				       const char *options)
{
	if (!device->port.membase)
		return -ENODEV;

	device->con->write = early_sailuart_write;
	return 0;
}

OF_EARLYCON_DECLARE(sailuart, "sail,sailuart", early_sailuart_setup);
#endif /* CONFIG_SERIAL_SAILUART_CONSOLE */

void sailuart_trace_write(int flag);
void sailuart_trace_write(int flag)
{
	struct sailuart_port *uart;
	struct uart_port *port;

	uart = &sailuart_ports[0];
	port = &uart->port;
	if (!port->membase)
		return;

	writel(flag, port->membase + OFF_TRACE);
}

static int __init sailuart_init(void)
{
	int res;

	res = uart_register_driver(&sailuart_driver);
	if (res)
		return res;

	res = platform_driver_register(&sailuart_platform_driver);
	if (res) {
		uart_unregister_driver(&sailuart_driver);
		return res;
	}

	return 0;
}

static void __exit sailuart_exit(void)
{
	platform_driver_unregister(&sailuart_platform_driver);
	uart_unregister_driver(&sailuart_driver);
}

module_init(sailuart_init);
module_exit(sailuart_exit);

MODULE_AUTHOR("Stuart Menefy <stuart.menefy@codasip.com>");
MODULE_DESCRIPTION("Sailuart serial driver");
MODULE_LICENSE("GPL v2");
MODULE_ALIAS("platform:sailuart");
