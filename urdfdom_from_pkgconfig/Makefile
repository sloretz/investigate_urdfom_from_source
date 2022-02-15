CFLAGS=`pkg-config --cflags urdfdom` -std=c++14
LDFLAGS=`pkg-config --libs urdfdom`
CC=g++

all: use_urdfdom

use_urdfdom: use_urdfdom.o
	$(CC) -o $@ $^ $(LDFLAGS)

use_urdfdom.o: use_urdfdom.cpp
	$(CC) -o $@ -c $^ $(CFLAGS)

test: use_urdfdom
	./use_urdfdom

clean:
	$(RM) use_urdfdom use_urdfdom.o
