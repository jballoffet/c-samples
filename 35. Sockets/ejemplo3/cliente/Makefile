#
# Makefile ejemplo
# Author: Javier F. Balloffet
# Date: 11-MAY-2018
#

AUTHOR="JavierBalloffet"
CLASS="R1041"
TP="TP1"
YEAR="2018"

CC=gcc
CFLAGS=-c -Wall
LDFLAGS=-lm

SOURCES=$(wildcard *.c)
OBJS=$(patsubst %.c, %.o, $(wildcard *.c))
HEADERS=$(wildcard *.h)
EXEC=cliente

FILE_NAME=$(AUTHOR)-$(CLASS)-$(TP)-$(YEAR).tar.gz

.PHONY: all clean compress edit run

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $@

%.o: %.c Makefile
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)

compress: $(SOURCES) $(HEADERS) Makefile
	tar -zcvf $(FILE_NAME) $(SOURCES) $(HEADERS) Makefile

edit: $(SOURCES) $(HEADERS) Makefile
	/opt/sublime_text/sublime_text $(SOURCES) $(HEADERS) Makefile

run: $(EXEC)
	./$(EXEC)
