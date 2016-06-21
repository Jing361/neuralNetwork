CC:=g++
SOURCES:=source/network.cc
OBJECTS:=$(subst source,object, $(subst .cc,.o, $(SOURCES)))
FLAGS:=-Wall -Wextra -pedantic -std=c++14 -I./header

name:=main

default:$(name)

$(name):object/$(name).o $(OBJECTS)
	$(CC) $+ $(FLAGS) -o $@

object/%.o:source/%.cc header/%.hh
	$(CC) -c source/$*.cc $(FLAGS) -o object/$*.o

.PHONY:
clean:
	rm object/*.o *.exe*
