package = mqtt-sample
version = 0.1

srcdir   = src
builddir = build
distdir  = $(package)-$(version)

prefix = /usr/local
bindir = $(prefix)/bin

export prefix
export bindir

CC      = gcc
CFLAGS  = -Wall -g -O2
LDFLAGS = -lm -lpaho-mqtt3c

all: prebuild $(builddir)/mqtt-pub $(builddir)/mqtt-sub

$(builddir)/mqtt-pub: $(srcdir)/mqtt-pub.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(builddir)/mqtt-sub: $(srcdir)/mqtt-sub.c $(srcdir)/callback.h
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

prebuild:
	mkdir -p $(builddir)

clean:
	rm -rf $(builddir)

install:
	install -d $(bindir)
	install -m 0755 $(builddir)/mqtt-pub $(bindir)
	install -m 0755 $(builddir)/mqtt-sub $(bindir)

uninstall:
	-rm $(bindir)/mqtt-pub
	-rm $(bindir)/mqtt-sub

dist: $(distdir).tar.gz

$(distdir).tar.gz: $(distdir)
	tar chof - $(distdir) | gzip -9 -c > $@
	rm -rf $(distdir)

$(distdir): distclean
	mkdir -p $(distdir)/src
	cp Makefile $(distdir)
	cp src/*.c $(distdir)/src
	cp src/*.h $(distdir)/src

distclean:
	-rm $(distdir).tar.gz > /dev/null 2>&1
	-rm -rf $(distdir) > /dev/null 2>&1

.PHONY: distclean all clean dist install uninstall