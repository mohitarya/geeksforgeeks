# Here bin is target
# main.o utill.o are files on which targets are dependent
# gcc -o bin main.o utill.o (Called RECIPE) By default recipe prefix is tab to cange it can use .RECIPEPREFIX to change it 

# $@ - Replace with target
# $^ - Replace with all prerequisites
# $< - Replace with first pre-requisites

# testing two types of variables

#x := foo
#y := $(x) bar
#x := later

#$(info [$x])

#a = foo
#b = $(a) bar
#a = later

#$(info [$a])

OBJECTS = main.o utill.o temp.o

VPATH = vpath_test/test 

bin : $(OBJECTS)
	gcc -o $@ $^

# $(OBJECTS) : utill.h temp.h

%.o : %.c

# Staic Pattern Rule Example

.PHONEY: all
all: $(OBJECTS) 

$(OBJECTS): %.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

# clean is a target which does not depend on any file it does used to do some actions this kind of target is called phony targets
clean:
	rm -rf $(OBJECTS) bin 
