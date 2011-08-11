#ifndef GRAPH_H
#define GRAPH_H
#include <vertex.h>
#include <common.h>
#include <vector>
#include <map>
using namespace std;
/*
    Graph class , creates vertex with all incoming and outgoing nodes associated to it
    singleton graph instance
*/


class Graph {

public:
    static Graph* get_Instance();
    bool is_vertex_present(node_t node) const;
    void add_vertex(Vertex &v);
    void remove_vertex(node_t node);
    unsigned int get_graph_size();
    map<node_t , Vertex> get_graph_nodes();
    Vertex get_vertex(node_t n);
    void print_graph(DIRECTION direction) const;
private:
    Graph();
    ~Graph();
    map<node_t,Vertex> mGraphNodes; // Can be replaced with maps
    static Graph* mInstance;

};

#endif
