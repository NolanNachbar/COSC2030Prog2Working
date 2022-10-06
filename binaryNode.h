#ifndef BINARYNODE_
#define BINARYNODE_
#include "binarySearchTree.h"

template<class T>
class binaryNode 
{

    public:
    T data;
    binaryNode<T> * left;
    binaryNode<T> * right;

    binaryNode( T d)
    : data (d), left (nullptr), right (nullptr) {}
        
};
#endif

