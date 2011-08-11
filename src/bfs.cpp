#include <iostream>
#include <string>
#include <queue>
#include <bfs.h>
#include <graph.h>


Bfs::Bfs(node_t src, node_t dest): PathFinder(src,dest) {

    mGraph = Graph::get_Instance();
}


Bfs::~Bfs(){

}


bool Bfs::traverse() {

    node_t source  = get_source();
    node_t target  = get_target();

    queue<node_t> bfsQueue;
    bool targetFound = false;

    bfsQueue.push(source);
    mDistSrc[source] = 0; 
    
    node_t v;
    cout << "Traverse Nodes:" <<endl;
    while(!bfsQueue.empty() && !targetFound) {
        v = bfsQueue.front();
  	bfsQueue.pop();

        if(v == target) {
            cout<< v <<endl;
            targetFound = true;
        }
	else if(mVisited.find(v) == mVisited.end() ) {

            mVisited[v] = true;
            Vertex curVer = mGraph->get_vertex(v);
            cout<< v <<"\t";
            vector<node_t> outNodes = curVer.get_outVertices();
            vector<node_t>::iterator itr = outNodes.begin();

            for(; itr != outNodes.end(); ++itr ) {
                if(mVisited.find(*itr) == mVisited.end()) {
                    bfsQueue.push(*itr);
                    if( mDistSrc.find(*itr) == mDistSrc.end() ) {
                        mDistSrc[*itr] =  (mDistSrc.find(v))->second + 1;
                    }
                }
            }
        }
    } // end of while loop 


    if(!targetFound) {
        cout<< "Target Not Found" <<endl;
        return false;
    }

#if 0 
    // Log for each node and it distance to target     
    map<node_t,unsigned int> :: iterator tr = mDistSrc.begin();
    for(;tr!= mDistSrc.end();++tr)
        cout<<"Node:"<<tr->first<<"\t  Distance:" <<tr->second <<endl;
#endif

    return true;

}

void Bfs::get_shortest_path() const {

    vector<node_t>::const_iterator itr = mShortPathNodes.begin();
    cout<<"The SHORTEST PATH is :"<<endl;
    cout<<"\n*-------------------------------------*"<<endl;
    for(; itr != mShortPathNodes.end(); ++itr) {
        cout<<"\t "<<*itr;
    }
    cout<<"\n*-------------------------------------*"<<endl;

}

vector<node_t> Bfs::get_shortestpath_nodes() const {

    return mShortPathNodes;
}

void Bfs::backtrace() {
    
    node_t target  = get_target();

    mShortPathNodes.resize(mDistSrc.find(target)->second + 1);
    mShortPathNodes[mDistSrc.find(target)->second] = target;
    unsigned int cur_path_len = mDistSrc.find(target)->second; 
    unsigned int i = mDistSrc.find(target)->second - 1;
    while(cur_path_len > 0) {
	Vertex curVer = mGraph->get_vertex(target);
        
	vector<node_t> inNodes = curVer.get_inVertices();
	vector<node_t>::const_iterator itr = inNodes.begin();

        for(; itr != inNodes.end(); ++itr ) {
            if(  mDistSrc.find(*itr) != mDistSrc.end() &&
                 (mDistSrc.find(*itr))->second < cur_path_len) {
                target = *itr;
                cur_path_len = mDistSrc.find(target)->second;
                mShortPathNodes[i] = target;
                i--;
                break;
            }
        }
    }

}
