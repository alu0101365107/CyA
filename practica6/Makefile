IDIR = ../include
CC = g++
CFLAGS = -I$(IDIR)

ODIR = .
LDIR = ../lib

LIBS=-lm

_DEPS =  cadena.h simbolo.h alfabeto.h automata.h 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = cliente.o simbolo.o alfabeto.o automata.o cadena.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

cliente: $(OBJ)
	$(CC) -std=c++14 -g -Wall -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
	rm -f $(ODIR)/cliente