CC:=g++
SOURCES:=object/network.cc
OBJECTS:=$(SOURCES:.cc=.o)
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
