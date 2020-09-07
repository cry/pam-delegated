CC=g++
CFLAGS=-Wall -std=c++20

LIBS=-lpam $$(pkg-config --libs libcurl)

all:
	$(CC) $(CFLAGS) -fPIC -c src/pam-delegated.cpp src/config.cpp
	$(CC) $(CFLAGS) -shared -o pam-delegated.so pam-delegated.o config.o $(LIBS)

clean:
	rm -f *.o *.so
