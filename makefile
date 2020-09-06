CC=g++

all:
	g++ -fPIC -c pam-delegated.cpp
	g++ -shared -o pam-delegated.so pam-delegated.o -lpam

clean:
	rm -f *.o *.so
