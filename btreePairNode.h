//
// Created by cielx on 1/12/2022.
//

#ifndef PRAED_BTREEPAIRNODE_H
#define PRAED_BTREEPAIRNODE_H

#include <iostream>
#include <utility>
#include <vector>
#include <set>

#include "double.h"

using namespace std;

// Cada nodo es un objeto pair<a, b>
// a -> monto
// b -> DoubleList<pair<int, int>>

template <typename T1, typename T2=DoubleList<pair<int, int>>>
struct btreePairNode:std::pair<T1, T2>{
    btreePairNode(){}
    btreePairNode(T1 first, T2 second):std::pair<T1, T2>(first, second){}
};

template <typename T>
bool operator<(const btreePairNode<T>& lhs,const btreePairNode<T>& rhs){
    if (lhs.first < rhs.first)
        return true;
    return false;
};

template <typename T>
bool operator>(const btreePairNode<T>& lhs,const btreePairNode<T>& rhs){
    if (lhs.first > rhs.first)
        return true;
    return false;
}

template <typename T>
bool operator!=(const btreePairNode<T>& lhs,const btreePairNode<T>& rhs){
    if(lhs.first != rhs.first)
        return true;
    return false;
}

template <typename T>
bool operator==(const btreePairNode<T>& lhs,const btreePairNode<T>& rhs){
    if(lhs != rhs)
        return false;
    return true;
}

//template <typename T>
//ostream& operator<<(std::ostream& os, const btreePairNode<T>& p){
//    os<<"("<<p.first<<")[";
//    for (auto i=(p.second).begin(); i != (p.second).end(); ++i){
//        os << "{" << (*i).first << "->" << (*i).second << "};";
//    }
//    os << "]";
//    return os;
//}

#endif //PRAED_BTREEPAIRNODE_H
