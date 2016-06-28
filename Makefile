CC:=g++

SOURCEDIR:=source
HEADERDIR:=header
OBJECTDIR:=object
BINARYDIR:=bin

SOURCES:=$(shell find $(SOURCEDIR) -name '*.cc')
OBJECTS:=$(subst source,object, $(subst .cc,.o, $(SOURCES)))

FLAGS:=-Wall -Wextra -pedantic -std=c++14 -I./$(HEADERDIR)

name:=main

default:$(name)

$(name):$(OBJECTDIR)/$(name).o $(OBJECTS)
	$(CC) $+ $(FLAGS) -o $@

$(OBJECTDIR)/%.o:$(SOURCEDIR)/%.cc $(HEADERDIR)/%.hh
	$(CC) -c $(SOURCEDIR)/$*.cc $(FLAGS) -o $(OBJECTDIR)/$*.o

.PHONY:
clean:
	rm $(OBJECTDIR)/*.o *.exe*
