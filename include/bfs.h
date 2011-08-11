#ifndef BFS_H
#define BFS_H
#include <iostream>
#include <vector>
#include <common.h>
#include <pathfinder.h>

using namespace std;

/*   
  Bfs  - Inherited class implementing traversing,calculating shortestpath & storing shortest path nodes for corresponding source node to target node
*/

class Bfs : public PathFinder {

public:
    Bfs(node_t src,node_t dest);
    ~Bfs();
    bool traverse();
    void backtrace();
    vector<node_t> get_shortestpath_nodes() const;
    void get_shortest_path() const;
private:
    vector<node_t> mShortPathNodes;
    Graph *mGraph;
    map<node_t,bool> mVisited;
    map<node_t,unsigned int> mDistSrc;
};
#endif 
