#ifndef PARSER_H
#define PARSER_H
#include <string>

using namespace std;

class Graph;
class Vertex;

/*
     Parse the file contents and build the graph
*/

class Parser {
public:
    Parser(string filePath);
    bool populate_graph_from_file();
    string get_graph_file() const;
private:
    string mfilePath;
    Graph *mGraph;
    Vertex *mVertex;
};
#endif
