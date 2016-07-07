CC:=g++

SOURCEDIR:=source
HEADERDIR:=header
OBJECTDIR:=object
DEPENDDIR:=dep
BINARYDIR:=bin

SOURCES:=$(shell find $(SOURCEDIR) -name '*.cc')
OBJECTS:=$(subst $(SOURCEDIR),$(OBJECTDIR), $(subst .cc,.o, $(SOURCES)))
DEPENDS:=$(subst $(SOURCEDIR),$(DEPNDDIR), $(SOURCES))

FLAGS:=-Wall -Wextra -pedantic -std=c++14 -I./$(HEADERDIR)

name:=main

default:$(name)

$(name):$(OBJECTDIR)/$(name).o $(OBJECTS)
	$(CC) $+ $(FLAGS) -o $@

-include $(DEPENDS)

$(OBJECTDIR)/%.o:$(SOURCEDIR)/%.cc $(HEADERDIR)/%.hh
	$(CC) -c $(SOURCEDIR)/$*.cc $(FLAGS) -o $@
	$(CC) -MM $(FLAGS) $(SOURCEDIR)/$*.cc > $(DEPENDDIR)/$*.d

clean:
	rm $(OBJECTDIR)/*.o *.exe* $(DEPENDDIR)/*.d

.PHONY:clean default

