CC=g++
CFLAGS=-Wall 

LIBS=-lpam $$(pkg-config --libs libcurl)

all:
	$(CC) $(CFLAGS) -fPIC -o pam-delegated.o -c src/pam-delegated.cpp
	$(CC) $(CFLAGS) -shared -o pam-delegated.so pam-delegated.o $(LIBS)

clean:
	rm -f *.o *.so
