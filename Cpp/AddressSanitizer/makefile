CC=g++
CXXFLAGS=-g -fsanitize=address 
LINKFALGS= -lasan
SOURCES = $(wildcard *.cc)
TARGETS = $(patsubst %.cc, %, $(SOURCES))

all:$(TARGETS)

$(TARGETS):%:%.cc
	$(CC) $< $(CXXFLAGS) $(LINKFALGS) -o $@

clean:
	rm -rf $(TARGETS)
