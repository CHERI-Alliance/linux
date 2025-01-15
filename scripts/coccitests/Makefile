.PHONY:	all force
.PRECIOUS: $(patsubst %.ok,%.out,$(wildcard */*.ok))

COCCI = ../coccinelle/cheri

V =

ifneq ($V,)
DIFFREDIR = &2
else
DIFFREDIR = /dev/null
endif

all: $(patsubst %.ok,%.out,$(wildcard */*.ok))

%.out: %.todo %.ok force
	@echo -n "Checking $(COCCI)/$(@D).cocci with $*.todo..."
	@diff -u "$*.todo" "$*.ok" >/dev/null && ( echo "NOTHING TO DO????"; false ) || true
	@spatch -D patch -sp-file $(COCCI)/$(@D).cocci --very-quiet "$*.todo" -o "$@" 2>/dev/null >/dev/null
	@diff -u "$@" "$*.ok" >$(DIFFREDIR) && echo ok || echo FAILED
