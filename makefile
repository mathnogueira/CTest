# Makefile used to compile the library as a shared object (.so)
#

LIB     = libctest.so
CC      = gcc -ansi
SRCDIR  = src
BINDIR  = build
DISTDIR = dist
SRCFMT  = c

# Files to compile
SRC     = $(wildcard $(SRCDIR)/*.$(SRCFMT))
OBJ     = ${SRC:.$(SRCFMT)=.o}
OUT     = $(subst $(SRCDIR)/, $(BINDIR)/, $(OBJ))
#IN		= $(subst $(SRCDIR)/,  , $(SRC))
# Compilation Flags
DEBUG   = -ggdb -O0 -pg
RELEASE = -O2
INCLUDE = -Iinclude -I /usr/include
CFLAGS  = -Wall -lm -c $(DEBUG) $(INCLUDE)

# Compilation
all: $(BINDIR) $(DISTDIR) $(LIB)

$(LIB): $(OUT)
	$(CC) $^ -shared -o $(DISTDIR)/$@

$(BINDIR)/%.o: $(SRCDIR)/%.$(SRCFMT)
	$(CC) -c -fPIC $(CFLAGS) $< -o $@

$(BINDIR) $(DISTDIR):
	mkdir -p $@

clean:
	rm dist/*
	rm $(BINDIR)/*
