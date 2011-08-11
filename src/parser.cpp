#include <parser.h>
#include <iostream>
//#include <locale>
#include <fstream>
#include <sstream>
#include <vector>
#include <graph.h>
#include <vertex.h>
#include <common.h>

Parser:: Parser(string fpath) {
    mfilePath = fpath;
}

/*
* Reading data set from the file and adding outgoing and incoming nodes to each node 
*/

bool Parser::populate_graph_from_file() {

    /* Get current Graph object Instance */
    mGraph = Graph::get_Instance();

    string eachline;
    node_t source;

    ifstream nodesDatafromFile( mfilePath, ios::in);
    if (!nodesDatafromFile)
    {
        cerr << "File could not be opened" << endl;
	return false;
    }

    while(getline(nodesDatafromFile,eachline))
    {
        string token;
        istringstream isstream (eachline);
        vector<node_t> vNodes;
        
	while ( getline( isstream ,token, ' ') )
        {
            /* converting each token (node) into node_t */
            istringstream src(token);
            src >> source;
            if (src.fail() || src.bad() ){
                cout <<"File Content not Good "<<endl;
		return false;
            }
            vNodes.push_back(source);
        } // end of while for tokens
	
	
      	Vertex vrtx(vNodes.at(0));
	bool vertex_present = false;
	/* 
	* Adding all outgoing nodes to current Vertex node
	*/
	if( mGraph->is_vertex_present(vNodes.at(0)) ) {
            vrtx =  mGraph->get_vertex(vNodes.at(0));
            vertex_present = true;
	}
	
        for(unsigned int i=1;i<vNodes.size();++i) {
            vrtx.add_vertex(vNodes.at(i),OUT);
        } 
	
        if(vertex_present) {
            mGraph->remove_vertex(vNodes.at(0));
	}
        mGraph->add_vertex(vrtx);
	/* 
	* Adding incoming  nodes to current Vertex node
	*/

        for(unsigned int i=1; i<vNodes.size(); ++i) {
            vertex_present = false;
            Vertex newvrtx(vNodes.at(i));
            if( mGraph->is_vertex_present(vNodes.at(i)) ) {
                newvrtx =  mGraph->get_vertex(vNodes.at(i));
                vertex_present = true;
            }

            newvrtx.add_vertex(vNodes.at(0),IN);
            if(vertex_present) {
                mGraph->remove_vertex(vNodes.at(i));
            }
            mGraph->add_vertex(newvrtx);
	}
        vNodes.clear();
    } //end of while for each line
    
    return true;
}

/*
* return input file name, used for logs
*/
string Parser::get_graph_file() const{

    return mfilePath;
}
