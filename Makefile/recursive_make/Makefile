# defining variables

.PHONEY: all

all: maindir subsystem

maindir: main.o
	$(CC) -o $@ $<

subsystem:
	$(MAKE) -C subdir all

clean:
	rm -f maindir *.o
	$(MAKE) -C subdir clean
