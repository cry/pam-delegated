CC=g++

CXXFLAGS=-Wall -std=c++20 -I./external/optional/include
LD_FLAGS=-lpam $$(pkg-config --libs libcurl) 

TEST_CXXFLAGS=-I./external/catch2/single_include -I./external/cpp-httplib -I./external/pam_wrapper/include

vpath %.cpp src

.PHONY: all

all: pam_delegated.so bin/test

obj/%.o: %.cpp | obj
	$(CC) $(CXXFLAGS) -fPIC -c -o $@ $<

pam_delegated.so: obj/pam_delegated.o obj/config.o
	$(CC) $(CXXFLAGS) $(LD_FLAGS) -shared -o pam_delegated.so $<

bin/test: | bin
	$(CC) $(CXXFLAGS) $(TEST_CXXFLAGS) $(LD_FLAGS) -o $@ test/main.cpp $<

runtest: bin/test pam_delegated.so
	LD_PRELOAD=pam_delegated.so ./bin/test

obj:
	mkdir -p $@

bin:
	mkdir -p $@

clean:
	rm -f */*.o */*.so bin/*
