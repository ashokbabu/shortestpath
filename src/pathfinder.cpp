#include <iostream>
#include <pathfinder.h>


PathFinder :: PathFinder(node_t src,node_t dest) {

    mSrc = src;
    mDest = dest;
}

PathFinder :: ~PathFinder() {

}

node_t PathFinder :: get_source() const {

    return mSrc;
}

node_t PathFinder :: get_target() const {

    return mDest;
}

