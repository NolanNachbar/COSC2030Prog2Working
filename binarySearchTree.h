#ifndef BINARYSEARCHTREE_
#define BINARYSEARCHTREE_
#include "binaryNode.h"

int tempNum =0;

template <class T>
class binarySearchTree
{
    public:
    void remove (T item);
    void insert (T item)
    {
        insert(item, root);
    }
    binaryNode<T> * find (T item, long long int & tempComp)
    {
        return find(item, tempComp,root);
    }
    bool isEmpty()
    {
        if(size == 0)
        {
            return true;
        }
        return false;
    }
    //posible methods: constructors/destructors isEmpty() Clear Prints

    private:
    int size;
    binaryNode<T> *root;
    binaryNode<T> *  find(T item, long long int &tempComp, binaryNode<T> * t)
    {
        if(t == 0)
        {
            return nullptr;
        }
        else if(item < t -> data)
        {
            tempComp++;
            return find(item, tempComp, t -> left);
        }
        else if(item > t -> data)
        {
            tempComp++;
            return find(item, tempComp, t -> right);
        }
        else
            tempComp++;
            return t; //the match case
    }

    void insert(T item, binaryNode<T> *&t)
    {
        if(t == nullptr)
        {
            t = new binaryNode<T>(item);
            size++;
        }
        else if(item < t -> data)
            insert(item, t -> left);
        else if(item > t -> data)
            insert(item, t -> right);
        else
            ; //duplicate case (won't do anything)
    }
};

#endif


