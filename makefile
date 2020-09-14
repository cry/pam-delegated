CC=g++
CFLAGS=-Wall -std=c++20 -I ./external/optional/include

LD_FLAGS=-lpam $$(pkg-config --libs libcurl) -L ./external/optional/include

all:
	$(CC) $(CFLAGS) -fPIC -c src/pam-delegated.cpp src/config.cpp
	$(CC) $(CFLAGS) -shared -o pam-delegated.so pam-delegated.o config.o $(LD_FLAGS)

clean:
	rm -f *.o *.so
