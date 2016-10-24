# defining variables

CFLAGS = -g
#export CFLAGS = -g

.PHONEY: all

all: maindir subsystem

maindir: main.o
	$(CC) $(CFLAGS) -o $@ $<

subsystem:
	$(MAKE) -C subdir all

clean:
	rm -f maindir *.o
	$(MAKE) -C subdir clean
	@#+ make -C subdir clean
