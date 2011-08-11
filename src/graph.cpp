#include <graph.h>
#include <iostream>
#include <iterator>


Graph::Graph() {
}


Graph::~Graph() {

}

Graph* Graph::mInstance =NULL;

Graph* Graph::get_Instance() {
    if(!mInstance)
        mInstance =  new Graph();
    return mInstance;
}

Vertex Graph::get_vertex(node_t node) {
    map<node_t,Vertex>::iterator itr = mGraphNodes.find(node);
    if( itr !=  mGraphNodes.end() ) {
        return itr->second;
    }
    Vertex v(0);
    return v;
}

void Graph::add_vertex(Vertex &v) { 

    mGraphNodes[v.get_vertex_id()] = v;

}

void Graph :: remove_vertex(node_t node) {
    mGraphNodes.erase(node);

}

bool Graph:: is_vertex_present(node_t node) const {

    map<node_t,Vertex>::const_iterator itr = mGraphNodes.find(node);
    
    if(itr != mGraphNodes.end())
        return true;
    return false;
}

unsigned int Graph::get_graph_size() {
    return mGraphNodes.size();
}

map<node_t, Vertex> Graph::get_graph_nodes() {

    return mGraphNodes;

}


void Graph::print_graph(DIRECTION dir) const {

    map<node_t,Vertex>::const_iterator itr = mGraphNodes.begin();
    cout<<"****************** "<<endl;
    cout<<"  Graph Data Set  "<<endl;
    cout<<"****************** "<<endl;
    
    for(; itr!= mGraphNodes.end() ; ++itr) {
    
	cout << (*itr).first<<" :";
        (*itr).second.print_vertex_nodes(dir);
    }

    cout<<"****************** "<<endl;
    
}

