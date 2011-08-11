#include <iostream>
#include <vertex.h>

Vertex::Vertex()
{
}

Vertex::Vertex(node_t vrtxid):mVertexId(vrtxid)
{
}

void Vertex:: setVertexId(node_t vid) {

    mVertexId = vid;

}

vector<node_t> Vertex:: get_inVertices() const{

    return mInVertices;

}

vector<node_t> Vertex:: get_outVertices() const{

    return mOutVertices;
}


bool Vertex:: add_vertex(node_t node,DIRECTION dir){

    if(dir == OUT)
	mOutVertices.push_back(node);
    if(dir == IN)
	mInVertices.push_back(node);
    return true;
}


unsigned int Vertex::get_degree() const{
    return (mInVertices.size()+mOutVertices.size());
}

unsigned int Vertex::get_in_degree() const{
    
    return mInVertices.size();
}

unsigned int Vertex::get_out_degree() const{
    return mInVertices.size();;
}


node_t Vertex::get_vertex_id(){
    return mVertexId;
}

void Vertex::print_vertex_nodes(DIRECTION dir) const{

    vector<node_t> vertices;

    if(dir == OUT)
	vertices.assign(mOutVertices.begin(),mOutVertices.end());
    else
	vertices.assign(mInVertices.begin(),mInVertices.end());


    vector<node_t>::iterator r = vertices.begin();

    for(;r!=vertices.end();++r)
        cout<< "   " << *r ;
    cout <<endl;
}
