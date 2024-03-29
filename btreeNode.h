//
// Created by cielx on 30/11/2022.
//

#ifndef PRAED_BTREENODE_H
#define PRAED_BTREENODE_H

#include <iostream>
#include <string>

using namespace std;

template <typename TK>
struct btreeNode {
    // array de keys
    TK* keys;
    // array de punteros a hijos
    btreeNode** children;
    // cantidad de keys
    int count;
    // indicador de nodo hoja
    bool leaf;

    btreeNode() : keys(nullptr), children(nullptr), count(0), leaf(true) {}
    btreeNode(int M, bool _leaf = true) {
        this->keys = new TK[M-1];
        this->children = new btreeNode<TK>*[M];
        for(int i=0; i < M; i++){
            this->children[i] = nullptr;
        }
        this->count = 0;
        this->leaf = _leaf;
    }

    int insert(TK value) {
        int i = this->count - 1;
        for(; i >= 0; i--){
            if(value > this->keys[i]){
                break;
            }else{
                this->keys[i+1] = this->keys[i];
            }
        }
        this->keys[i + 1] = value;
        (this->count)++;
        return i+1;
    }

    int insert(btreeNode<TK>* node, int M, btreeNode<TK>* cmp) {
        int i = M - 1;
        for(; i >= 0; i--){
            if(children[i] == cmp){
                break;
            }else{
                this->children[i+1] = this->children[i];
            }
        }
        this->children[i + 1] = node;
        return i+1;
    }

    void print(){
        for(int i = 0; i < this->count; i++){
            cout<<this->keys[i]<<" ";
        }
        cout<<endl;
    }

    void killSelf() {
        for(int i = 0; i<= this->count; i++){
            if(this->children[i] != nullptr){
                this->children[i]->killSelf();
            }
        }
        if(this->keys != nullptr) delete[] this->keys;
        if(this->children[0] == nullptr) delete[] this->children;
        delete this;
    }

    void display(const string& sep = ",") {
        int i;
        for(i = 0; i < count; i++){
            if(children[i] != nullptr){
                children[i]->display();
            }
            cout<<keys[i]<<sep;
        }
        if(children[i] != nullptr){
            children[i]->display();
        }
    }

    void toString(string& result, const string& sep = ",") {
        int i;
        for(i = 0; i < count; i++){
            if(children[i] != nullptr){
                children[i]->toString(result, sep);
            }
            result += std::to_string(keys[i]) + sep;
        }
        if(children[i] != nullptr){
            children[i]->toString(result, sep);
        }
    }

    template<typename List, typename T>
    void getRange(List& list, T min, T max) {
        if (min > max) return;
        int i;
        for(i = 0; i < count; i++){
            if( keys[i].first >= min){
                if(children[i] != nullptr){
                    children[i]->getRange(list, min, max);
                }
            }
            if( keys[i].first >= min && keys[i].first <= max) {
                for (auto it = keys[i].second.begin(); it != keys[i].second.end(); ++it) {
                    list.push_back(*it);
                }
            }
        }
        if( keys[i].first <= max){
            if(children[i] != nullptr){
                children[i]->getRange(list, min, max);
            }
        }
    }

    void display_keys(const string& sep = ",") {
        int i;
        for(i = 0; i < count; i++){
            cout<<keys[i]<<sep;
        }
    }

    void remove(int idx){
        for (;idx<count-1; idx++){
            this->keys[idx] = this->keys[idx+1];
        }
        this->count = this->count-1;
    }

    void remove(int idx, int M){
        for (;idx<=count; idx++){
            this->children[idx] = this->children[idx+1];
        }
        for (int i = this->count + 1; i < M; i++){
            this->children[i] = nullptr;
        }
    }
};

#endif //PRAED_BTREENODE_H
