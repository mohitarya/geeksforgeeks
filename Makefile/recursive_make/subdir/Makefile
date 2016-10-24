# defining variables

.PHONEY: all

all: maindir 

maindir: main.o
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f *.o maindir
