#include <iostream>
#include <locale>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>

#include <parser.h>
#include <common.h>
#include <pathfinder.h>
#include <graph.h>
#include <bfs.h>
#include <fileexception.h>
using namespace std;

/*
* Entry Point
* Usage <executable> <filename> <sourcenode> <targetnode>
*/

int main(int argc, char *argv[])
{

    // If the user didn't provide a filename command line argument,
    // print an error and exit or throw exception.
    if (argc <= 3)
    {
        cout << "Usage: " << argv[0] << " <Filename> <SourceNode> <TargetNode>" << endl;
        exit(1);
    }

    string filename = argv[1];
    string srcnode = argv[2];
    string trgnode = argv[3];

    try{

        if(srcnode.compare(trgnode)== 0){
            throw BaseException("No Shortest Path Between Same Nodes");
        }

        // open file and process it to Parser
        // write try catch and throw Exception
        Parser prsr(filename);
        if(!prsr.populate_graph_from_file()){
            throw FileNotFoundException("File not present or Wrong File Contents, unable to parse");

        }

        /* Printing Graph nodes to reverify with the data set */
        Graph *mGraph =  Graph::get_Instance();
        mGraph->print_graph(OUT);

        node_t source,target;
        istringstream src(srcnode);
        src >> source;

        istringstream trg(trgnode);
        trg >> target;

	if(!mGraph->is_vertex_present(source)){
	  cout<<endl << "Source Node not present in the Graph"<<endl;
	  return FAILURE;
	}

	if(!mGraph->is_vertex_present(target)){
	  cout << endl<<"Target Not Found in the Graph"<<endl;
	  return FAILURE;
	}


        PathFinder *pathFinder;
        pathFinder = new Bfs(source,target);
        if(!pathFinder->traverse()){
            cout << "No Path to Target from Source..Not Found" <<endl;
            //call exception saying.. Target Not found
        }else{
            cout <<"BFS Sucess " << endl;
            pathFinder->backtrace();
            pathFinder->get_shortest_path();
        }

        delete pathFinder;

    }catch(FileNotFoundException& e){
        cout << "Exception: " << e.getMessage()<<endl;
    }catch(BaseException& e){
        cout << "Exception Raised: " << e.getMessage()<<endl;
    }catch(...){	
	cout << " Unknown Exception Raised"<<endl ;
    }

    return SUCCESS;
}

