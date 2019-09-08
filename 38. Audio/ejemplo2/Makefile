all:
	gcc main.c `pkg-config --cflags libvlc` `pkg-config --libs libvlc` -o program
	# gcc main.c -l vlc -o program
clean:
	rm -f program
