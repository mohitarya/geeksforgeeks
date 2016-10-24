# defining variables

.PHONEY: all

all: maindir 

maindir: main.o
	$(CC) -o $@ $<

clean:
	rm -f *.o maindir
