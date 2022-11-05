# Author: Javier Balloffet <javier.balloffet@gmail.com>
# Date:   Oct 24, 2021

SOURCES = $(wildcard *.c)
HEADERS = $(wildcard *.h)
OBJS    = $(patsubst %.c, %.o, $(SOURCES))
EXEC    = app

CC      = gcc
CFLAGS  = -c -Wall `pkg-config --cflags gtk+-3.0 libvlc`
LDFLAGS = `pkg-config --libs gtk+-3.0 libvlc`

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
