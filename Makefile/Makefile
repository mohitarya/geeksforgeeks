# Here bin is target
# main.o utill.o are files on which targets are dependent
# gcc -o bin main.o utill.o (Called RECIPE) By default recipe prefix is tab to cange it can use .RECIPEPREFIX to change it 

OBJECTS = main.o utill.o temp.o

bin : $(OBJECTS)
	gcc -o bin $(OBJECTS) 

$(OBJECTS) : utill.h temp.h


# clean is a target which does not depend on any file it does used to do some actions this kind of target is called phony targets
clean:
	rm -rf $(OBJECTS) bin 
