CFLAGS = `pkg-config --cflags opencv`
LDFLAGS = `pkg-config --libs opencv`

all:
	g++ main.c $(CFLAGS) $(LDFLAGS) -o program
clean:
	rm -f program
