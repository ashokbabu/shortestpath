#ifndef VERTEX_H
#define VERTEX_H

#include <common.h>
#include <vector>
#include <cstdlib>

using namespace std;
/* 
   vertex class
   Each vertex object has an associated outgoing and incoming nodes
	
 */

class Vertex {
public:
    Vertex();
    Vertex(node_t vrtxid);
    void setVertexId(node_t vrtxid);
    vector<node_t> get_inVertices() const;
    vector<node_t> get_outVertices() const;
    bool add_vertex(node_t node, DIRECTION dir);	
    unsigned int get_degree() const;
    unsigned int get_in_degree() const;
    unsigned int get_out_degree() const;
    void print_vertex_nodes(DIRECTION dir) const;

    node_t get_vertex_id();
private:
    node_t mVertexId;
    vector<node_t> mInVertices;
    vector<node_t> mOutVertices;
};

#endif
