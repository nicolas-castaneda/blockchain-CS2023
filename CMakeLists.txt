cmake_minimum_required(VERSION 3.20)
project(prAED)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(prAED
        block.h
        blockchain.h
        main.cpp
        merkle.h
        merkle.cpp
        sha256.cpp
        sha256.h
        transaction.h
        node.h
        list.h
        double.h
        circulararray.h
        trie.h
        heapNode.h
        minHeap.h
        maxHeap.h
        simple_list.h
        datastructures.h
        chainhash.h btree.h btreeNode.h btreePairNode.h app.h)
