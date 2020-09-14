CC=g++

CXXFLAGS=-Wall -std=c++20 -I./external/optional/include
LD_FLAGS=-lpam $$(pkg-config --libs libcurl) 

TEST_CXXFLAGS=-I./external/catch2/single_include/catch2 -I./external/pam_wrapper/include

vpath %.cpp src

.PHONY: all

all: pam-delegated.so bin/test

obj/%.o: %.cpp | obj
	$(CC) $(CXXFLAGS) -fPIC -c -o $@ $<

pam-delegated.so: obj/pam-delegated.o obj/config.o
	$(CC) $(CXXFLAGS) $(LD_FLAGS) -shared -o pam-delegated.so $<

bin/test: pam-delegated.so | bin
	$(CC) $(CXXFLAGS) $(TEST_CXXFLAGS) $(LD_FLAGS) -o $@ test/main.cpp $<

obj:
	mkdir -p $@

bin:
	mkdir -p $@

clean:
	rm -f *.o *.so
