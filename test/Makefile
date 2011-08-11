CXXFLAGS=-pipe -Wall -I../include -I../../common -I. -g -std=gnu++0x
VPATH=..
LIBS=-lcppunit -lpthread

SRCOBJS= ../src/parser.o ../src/vertex.o ../src/graph.o \
		 ../src/pathfinder.o ../src/bfs.o \
		 ../src/baseexception.o

all: testsuite

testsuite: main.o $(SRCOBJS)
	$(CXX) $(LDFLAGS) -o $@ $+ $(LIBS)

clean:
	rm -f *.o ../src/*.o testsuite testresult.xml
