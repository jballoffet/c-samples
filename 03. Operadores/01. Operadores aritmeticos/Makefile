################################################################
# SOURCES, HEADERS, OBJECTS, LIBRARIES AND EXECUTABLES         #
################################################################

APP_SOURCES = $(shell find . -name '*.c')
APP_HEADERS = $(shell find . -name '*.h')
APP_OBJS    = $(patsubst %.c, %.o, $(APP_SOURCES))
APP_EXEC    = app.out

################################################################
# COMPILER AND ARGUMENTS                                       #
################################################################

CC          = gcc
CFLAGS      = -c -Wall

################################################################
# MAKE TARGETS                                                 #
################################################################

.PHONY: all clean help

all: $(APP_EXEC)

$(APP_EXEC): $(APP_OBJS)
	@echo '[LD] Linking C executable $@'
	@$(CC) $(APP_OBJS) -o $@
	@echo 'Built target $@'

%.o: %.c Makefile
	@echo '[CC] Compiling C object $@'
	@$(CC) $(CFLAGS) $< -o $@

clean:
	@echo '[CLEAN] Cleaning workspace'
	@rm -rf $(APP_OBJS) $(APP_EXEC)

help:
	@echo ''
	@echo '********************************************************'
	@echo '  Uso:'
	@echo '    make all:       Compila la aplicacion'
	@echo '    make clean:     Elimina archivos objeto y ejecutable'
	@echo '    make help:      Muestra la ayuda'
	@echo '********************************************************'
	@echo ''
