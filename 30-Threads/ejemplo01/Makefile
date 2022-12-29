# Author: Javier Balloffet <javier.balloffet@gmail.com>
# Date:   Jul 5, 2019

SOURCES = $(wildcard *.c)
HEADERS = $(wildcard *.h)
OBJS    = $(patsubst %.c, %.o, $(SOURCES))
EXEC    = app

CC      = gcc
CFLAGS  = -c -Wall
LDFLAGS = -lpthread

.PHONY: all clean help

## all:   Compila la aplicacion
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $@

%.o: %.c Makefile
	$(CC) $(CFLAGS) $< -o $@

## clean: Elimina archivos objeto y ejecutable
clean:
	rm -f $(OBJS) $(EXEC)

## help:  Muestra la ayuda
help:
	@sed -n 's/^## //p' Makefile
