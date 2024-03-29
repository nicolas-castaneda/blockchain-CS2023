/* #include "double.h"
#include <iostream>
#include <string>

using namespace std;
const unsigned ALPHA_SIZE = 26;//tamanio del alfabeto: letras minusculas

class TrieSimple{
private:
    struct TrieNode{
        // opcion 1:   TrieNode **children;           
        // opcion 2:   list<pair<char, TrieNode*>> children;        
        // opcion 3:   map<pair<char, TrieNode*>> children;   
        TrieNode **children;        
        bool endWord; //indica si es final de una palabra
        DoubleList<pair<int,int>>* indexes; // almacenar indices de los bloques
        DoubleList<pair<int,int>>* getIndex() { return indexes;}
        int count;
        TrieNode(){
            endWord = false;
            this->children = new TrieNode*[ALPHA_SIZE];
            for (int i = 0; i < ALPHA_SIZE; i++) {
                this->children[i] = nullptr;
            }
            count = 0;
        };        

        void killSelf() {
            for(int i = 0; i < ALPHA_SIZE; i++){
                if(this->children[i] != nullptr){
                    this->children[i]->killSelf();
                }
            }
            if(this->children){delete[]children;}
            this->children = nullptr;
            
            if(this!= nullptr)delete this; 
            } 
    };

    TrieNode* root;

public:
    TrieSimple(): root(nullptr) {}

    ~TrieSimple(){
        if(this->root){
            root->killSelf();
        }
    }

    void insert(string key, int num){
        if(this->root == nullptr){
            this->root = new TrieNode();
        }
        TrieNode* node = root;
        int index;
        for(int i=0; i<key.size(); i++){
            index = key[i] - 'a';
            if(node->children[index] == nullptr){
                ++(node->count);
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->endWord = true;
        node->indexes->push_back(num);
    };

    pair<bool,ListNode<int>*> search(string key){
        if(root==nullptr)return std::make_pair(false, nullptr);
        TrieNode* node = root;
        int index;
        for(int i=0; i<key.size(); i++){
            index = key[i] - 'a';
            if(node->children[index] != nullptr)
                node = node->children[index];
            else
                return std::make_pair(false, nullptr);
        }
        return std::make_pair(node->endWord, node->getIndex());
    };

    void remove(string key){
        if(root==nullptr)return;
        TrieNode* node = root;
        remove(key, node, 0);
    }

    void remove(string key, TrieNode* node, int i){
        int index = key[i] - 'a';

        if(i == key.size()){
            node->endWord = false;
        }
        else{
            if(node->children[index] != nullptr){    
                remove(key, node->children[index], i+1);
                if(node->children[index]->count == 0 && !node->children[index]->endWord){
                    delete [] node->children[index]->children;
                    node->children[index]->children = nullptr;
                    delete node->children[index];
                    node->children[index] = nullptr;
                    --(node->count);
                }else{
                    return;
                }
            }else{
                return;
            }
        }
    }
    
    //imprime ordenado
    string toString(string sep){
        return toString(root, sep, "");
    }
    string toString(TrieNode* node, string sep, string prefix){
        if(root == nullptr) return "";
        string result = "";
        if(node->endWord) result += prefix + sep;

        for(int i=0;i < ALPHA_SIZE;i++){
                if(node->children[i] != nullptr)
                    result += toString(node->children[i], sep, prefix + char('a' + i));
        }
        return result;
    };

}; */