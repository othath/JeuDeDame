# Makefile générique (sysol)
# --------------------- Zone modifiable --------------------------

# Source C destiné à fournir l'exécutable (ou les exécutables)
# MAINSRCS= main.c
MAINSRCS= $(wildcard src/main*.c)

# Ci-dessous, tous les fichiers *.c à l'exception du ou des précédents, sont 
# des librairies avec entêtes *.h
LIBSRCS=$(filter-out $(MAINSRCS), $(wildcard src/*.c))

# CPPFLAGS : options propres au préprocesseur
# CFLAGS : options propres au compilateur C
# LDFLAGS : options propres à l'éditeur de liens
# LDLIBS : librairies à intégrer à l'édition de liens

#CPPFLAGS=
CPPFLAGS=
CFLAGS= -Wall `pkg-config --cflags gtk+-3.0`
LDFLAGS=
LDLIBS= -lm `pkg-config --libs gtk+-3.0`

# --------------------- Zone non modifiable --------------------------

EXECS = $(patsubst %.c,%,$(MAINSRCS))
MAINOBJS=$(patsubst %.c,%.o,$(MAINSRCS))
LIBHS=$(LIBSRCS:.c=.h)
LIBOBJS=$(LIBSRCS:.c=.o)

# Règles

.PHONY: clean doc
	
all: $(EXECS)

$(MAINOBJS) : %.o :%.c $(LIBHS) $(COMMONHS) $(MAINHS)
	$(CC) -c -o $@ $(CFLAGS) $(CPPFLAGS) $<

$(LIBOBJS) : %.o :%.c $(COMMONHS)
	$(CC) -c -o $@ $(CFLAGS) $(CPPFLAGS) $<
	
$(EXECS) : % : %.o $(LIBOBJS)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@
	mv $@ dames

clean: 
	rm -f $(EXECS) src/*.o dames

docs:
	doxygen Doxyfile
	rm documentation.html
	ln -s doc/html/index.html documentation.html
