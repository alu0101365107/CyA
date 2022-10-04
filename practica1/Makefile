IDIR = ../include
CC = g++
CFLAGS = -I$(IDIR)

ODIR = .
LDIR = ../lib

LIBS=-lm

_DEPS = fichero.h simbolo.h cadena.h  alfabeto.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main_test.o fichero.o simbolo.o cadena.o  alfabeto.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main_test: $(OBJ)
	$(CC) -std=c++14 -g -Wall -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
	rm -f $(ODIR)/main_test