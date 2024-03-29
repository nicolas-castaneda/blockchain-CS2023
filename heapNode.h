#ifndef HEAPNODE_H
#define HEAPNODE_H

#include <iostream>
#include <utility>
#include <vector>
#include <set>

#include "double.h"

using namespace std;

// Cada nodo es un objeto pair<a, b>
// a -> monto
// b -> pair<idx_Block, idx_Trnasaction>

template <typename T1, typename T2=pair<int, int>>
struct heapNode:std::pair<T1, T2>{
    heapNode(){}
    heapNode(T1 first, T2 second):std::pair<T1, T2>(first, second){}
};

template <typename T>
bool operator<(const heapNode<T>& lhs,const heapNode<T>& rhs){
    if (lhs.first < rhs.first)
        return true;
    return false;
};

template <typename T>
bool operator>(const heapNode<T>& lhs,const heapNode<T>& rhs){
    if (lhs.first > rhs.first)
        return true;
    return false;
}

template <typename T>
bool operator!=(const heapNode<T>& lhs,const heapNode<T>& rhs){
    if(lhs.first != rhs.first)
        return true;
    return false;
}

template <typename T>
bool operator==(const heapNode<T>& lhs,const heapNode<T>& rhs){
    if(lhs != rhs)
        return false;
    return true;
}

template <typename T>
ostream& operator<<(std::ostream& os, const heapNode<T>& p){
    os<<"("<<p.first<<")[";
    os<<p.second.first<<","<<p.second.second<<"]";
    return os;
}

#endif