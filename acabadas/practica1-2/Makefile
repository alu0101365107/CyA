IDIR = ../include
CC = g++
CFLAGS = -I$(IDIR)

ODIR = .
LDIR = ../lib

LIBS=-lm

_DEPS = funciones.h simbolo.h cadena.h alfabeto.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = alfabeto_cliente.o funciones.o simbolo.o cadena.o  alfabeto.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

alfabeto_cliente: $(OBJ)
	$(CC) -std=c++14 -g -Wall -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
	rm -f $(ODIR)/alfabeto_cliente