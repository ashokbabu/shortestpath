SOURCE= src/main.cpp src/parser.cpp src/graph.cpp src/vertex.cpp src/pathfinder.cpp src/bfs.cpp src/baseexception.cpp
PROGRAM=shortestpath
INCLUDES=include/
	
#MYLIBRARIES=
CC=g++


all: $(PROGRAM)

$(PROGRAM): $(SOURCE)

	$(CC) -g -std=gnu++0x -I$(INCLUDES) $(SOURCE) -o$(PROGRAM) 
#-l$(MYLIBRARIES)

clean:

	rm -f $(PROGRAM) src/*.o
