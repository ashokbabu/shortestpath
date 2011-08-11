#ifndef PATHFINDER_H
#define PATHFINDER_H
#include <iostream>
#include <common.h>
#include <graph.h>
#include <vector>
#include <map>

using namespace std;

/*   
  PathFinder - Abstract class for implementing traversing algorithm
	       calculating shortestpath & storing shortest path nodes.
*/

class PathFinder {

public:
    PathFinder(node_t src, node_t dest);
    virtual ~PathFinder();
    virtual bool traverse() = 0;
    virtual void get_shortest_path() const = 0;
    virtual vector<node_t> get_shortestpath_nodes() const = 0;
    virtual void backtrace() = 0;
    node_t get_source() const;
    node_t get_target() const;
private:
    node_t mSrc;
    node_t mDest;
    Graph *mGraph;
    map<node_t,unsigned int> mLevelofVistedNodes;
    vector<node_t> mShortPathNodes;
};
#endif
