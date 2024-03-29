//
// Created by cielx on 30/11/2022.
//

#ifndef PRAED_BTREE_H
#define PRAED_BTREE_H

#include <iostream>
#include <stack>
#include <math.h>
#include <queue>
#include "btreeNode.h"

using namespace std;

template<typename TK>
struct SplitResult
{
    TK key;
    btreeNode<TK> *right_tree;
    SplitResult(){right_tree = nullptr;}
    SplitResult(TK _k, btreeNode<TK> *_node) : key(_k), right_tree(_node){}
};

template <typename TK>
class BTree {
private:
    btreeNode<TK>* root;
    int M;  // grado u orden del arbol
    int n; // total de elementos en el arbol

public:
    BTree(int _M) : root(nullptr), M(_M), n(0) {}

    TK& get(TK key){return get(this->root, key);};//indica si se encuentra o no un elemento
    bool search(TK key){return search(this->root, key);};//indica si se encuentra o no un elemento
    void insert(TK key);//inserta un elemento
    void remove(TK key);//elimina un elemento
    int height(){return height(this->root);};//altura del arbol. Considerar altura -1 para arbol vacio
    string toString(const string& sep){return toString(this->root, sep);};  // recorrido inorder

    TK minKey(){return minKey(this->root);};  // minimo valor de la llave en el arbol
    TK maxKey(){return maxKey(this->root);};  // maximo valor de la llave en el arbol
    void clear(){this->root->killSelf(); this->root = nullptr; n = 0;}; // eliminar todos lo elementos del arbol
    int size(){return n;}; // retorna el total de elementos insertados
    ~BTree(){if(this->root != nullptr) {this->root->killSelf();}};     // liberar memoria

    void display_pretty(){display_pretty(this->root);};

    template<typename T>
    DoubleList<pair<int,int>> get_range(T min, T max){
        DoubleList<pair<int,int>> res = DoubleList<pair<int,int>>();
        root->getRange( res, min, max);
        return res;
    };

private:

    TK& get(btreeNode<TK>*& node, TK key);
    SplitResult<TK>* insert(btreeNode<TK>* &node, TK key);
    void relocate(btreeNode<TK>* &node, TK key, btreeNode<TK>* key_right_tree = nullptr);
    btreeNode<TK> *generate_right_node(btreeNode<TK> *&node, int from);
    SplitResult<TK> *split_par(btreeNode<TK> *&node, TK key, btreeNode<TK> *key_right_tree = nullptr);
    SplitResult<TK> *split_impar(btreeNode<TK> *&node, TK key, btreeNode<TK> *key_right_tree = nullptr);

    void remove(btreeNode<TK>* child, btreeNode<TK>* parent, TK key);
    btreeNode<TK>* successor(btreeNode<TK>* node, int idx);
    btreeNode<TK>* predecessor(btreeNode<TK>* node, int idx);
    btreeNode<TK>* minNode(btreeNode<TK>* node);
    btreeNode<TK>* maxNode(btreeNode<TK>* node);

    int height(btreeNode<TK>* node);
    string toString(btreeNode<TK>* node, const string& sep);

    TK minKey(btreeNode<TK>* node);
    TK maxKey(btreeNode<TK>* node);

    void display_pretty(btreeNode<TK>* root);

    bool search(btreeNode<TK> *&node, TK key);
};

template<typename TK>
TK& BTree<TK>::get(btreeNode<TK>*& node, TK key){
    if(node == nullptr){throw std::out_of_range("Key not found");}

    for(int i = 0; i < node->count; i++){
        if(node->keys[i] == key){
            return node->keys[i];
        } else{
            if(key < node->keys[i]){
                return get(node->children[i], key);
            }
            if(i+1 == node->count){
                return get(node->children[i+1], key);
            }
        }
    }
    throw std::out_of_range("Key not found");
}

template<typename TK>
bool BTree<TK>::search(btreeNode<TK>*& node, TK key){
    if(node == nullptr){return false;}

    for(int i = 0; i < node->count; i++){
        if(node->keys[i] == key){
            return true;
        } else{
            if(key < node->keys[i]){
                return search(node->children[i], key);
            }
            if(i+1 == node->count){
                return search(node->children[i+1], key);
            }
        }
    }
    return false;
}

template<typename TK>
void BTree<TK>::remove(TK key){
    if(this->root != nullptr){
        remove(this->root, this->root, key);
    }
    (this->n)--;
}

template<typename TK>
void BTree<TK>::remove(btreeNode<TK>* child, btreeNode<TK>* parent, TK key){
    int i = 0;
    bool found = false;
    for(; i < child->count;i++){
        if(key == child->keys[i]){
            found = true;
            break;
        }
    }
    // *No se encontro y es un nodo hoja.
    if (!found & child->leaf){
        return;
    }
        // *No se encontro y es un nodo interno.
    else if(!found & !child->leaf){
        int idx = 0;
        for(; idx<child->count; idx++){
            if(key < child->keys[idx]){
                remove(child->children[idx], child, key);
                break;
            }
            else if (idx+1 == child->count){
                remove(child->children[idx+1], child, key);
                break;
            }
        }
    }
        // *Se encontro y es un nodo hoja.
    else if (found & child->leaf){
        child->remove(i);
    }
        // *Se encontro y es un nodo interno.
    else if (found & !child->leaf){
        btreeNode<TK>* sc = successor(child, i);
        TK temp = sc->keys[0];
        sc->keys[0] = key;
        child->keys[i] = temp;
        remove(child->children[i+1], child, key);
        //return; // warning
    }

    // !Important
    int minKeys = floor((this->M-1)/2);
    if (child->count < minKeys && child != this->root){
        int ichild = 0;
        for (;ichild<=parent->count; ichild++){
            if (parent->children[ichild] == child){
                break;
            }
        }
        btreeNode<TK>* hermano = nullptr;
        int idxKeyParent;
        int idxNodeHermano;
        bool right = false;
        if (ichild == 0) // *Inmediato derecho.
        {
            idxNodeHermano = ichild+1;
            idxKeyParent = ichild;
            right = true;
            if(parent->children[ichild+1]->count > minKeys){
                hermano = parent->children[ichild+1];
            }
        }
        else if (ichild == parent->count) // *Inmediato izquierdo.
        {
            idxKeyParent = ichild-1;
            idxNodeHermano = ichild-1;
            if(parent->children[ichild-1]->count > minKeys){
                hermano = parent->children[ichild-1];
            }
        }
        else if (0 < ichild & ichild < parent->count) // *Inmediato derecho e izquierdo.
        {
            if(parent->children[ichild+1]->count > minKeys){
                hermano = parent->children[ichild+1];
                idxKeyParent = ichild;
                right = true;
            } else if(parent->children[ichild-1]->count > minKeys){
                hermano = parent->children[ichild-1];
                idxKeyParent = ichild-1;
            } else {
                idxNodeHermano = ichild + 1;
                idxKeyParent = ichild;
                right = true;
            }
        }

        // Rotacion
        if(hermano != nullptr){
            child->insert(parent->keys[idxKeyParent]);
            parent->remove(idxKeyParent);
            right? parent->insert(hermano->keys[0]):parent->insert(hermano->keys[hermano->count-1]);
            right? hermano->remove(0):hermano->remove(hermano->count-1);
            if(!(child->leaf)){
                if(right){
                    child->children[child->count] = hermano->children[0];
                    hermano->remove(0,this->M);
                }else{
                    for(int i=child->count; i >= 0; i--){
                        child->children[i+1] = child->children[i];
                    }
                    child->children[0] = hermano->children[hermano->count+1];
                    hermano->remove(hermano->count+1,this->M);
                }
            }
            // Merge
        }else{

            btreeNode<TK>* hermano = parent->children[idxNodeHermano];
            if(!right){
                btreeNode<TK>* temp = child;
                child = hermano;
                hermano = temp;
                idxNodeHermano++;
            }

            // Inserta elementos del hermano al nodo
            int idxInsertedParent = child->insert(parent->keys[idxKeyParent]);
            parent->remove(idxKeyParent);
            for(int idx_hermano=0; idx_hermano<hermano->count;idx_hermano++){
                child->insert(hermano->keys[idx_hermano]);
            }
            // Inserta hojas del nodo hermano al nodo merge
            if(!(child->leaf)){
                for(int idx_child_hermano = 0; idx_child_hermano <= hermano->count; idx_child_hermano++){
                    child->children[idxInsertedParent+1] = hermano->children[idx_child_hermano];
                    hermano->children[idx_child_hermano] = nullptr;
                    idxInsertedParent++;
                }
            }
            btreeNode<TK>* temp = hermano;
            parent->remove(idxNodeHermano, this->M);

            temp->killSelf();
        }
    } else if (child == this->root && child->count == 0){
        if(child->children[0] != nullptr){
            btreeNode<TK>* temp = child->children[0];
            child->children[0] = nullptr;
            this->root->killSelf();
            this->root = temp;
        }
    }
}

template<typename TK>
btreeNode<TK>* BTree<TK>::successor(btreeNode<TK>* node, int idx){
    return minNode(node->children[idx+1]);
}

template<typename TK>
btreeNode<TK>* BTree<TK>::predecessor(btreeNode<TK>* node, int idx){
    return maxNode(node->children[idx-1]);
}

template<typename TK>
btreeNode<TK>* BTree<TK>::minNode(btreeNode<TK>* node){
    if(node->leaf){
        return node;
    }else{
        return minNode(node->children[0]);
    }
}

template<typename TK>
btreeNode<TK>* maxNode(btreeNode<TK>* node){
    if(node->leaf){
        return node;
    }else{
        return maxNode(node->children[node->count]);
    }
}

template<typename TK>
void BTree<TK>::insert(TK key){
    if(this->root == nullptr){
        this->root = new btreeNode<TK>(this->M, true);
        root->insert(key);
    }else{
        SplitResult<TK>* split_result = insert(this->root, key);
        if(split_result != nullptr){
            btreeNode<TK> *parent = new btreeNode<TK>(M, false);
            parent->keys[0] = split_result->key;
            parent->children[0] = root;
            parent->children[1] = split_result->right_tree;
            parent->count = 1;
            root = parent;
        }
    }
    (this->n)++;
}

template<typename TK>
SplitResult<TK>* BTree<TK>::insert(btreeNode<TK>* &node, TK key){
    int i = 0;
    while (i < node->count && key > node->keys[i])
        i++;
    if (i < node->count && node->keys[i] == key)
        return nullptr;

    if (node->leaf)
    {
        // si la hoja tiene espacio, insertar
        if (node->count < M - 1)
            relocate(node, key);
            // dividir y retornar el resultado al antecesor
        else if (M % 2 == 0)
            return split_par(node, key);
        else
            return split_impar(node, key);
    }
        // es nodo interno
    else
    {
        // insertar en el hijo respectivo
        SplitResult<TK> *split_result = insert(node->children[i], key);
        // si split_result != null es porque se produjo un split en el children[i]
        if (split_result != nullptr)
        {
            // si hay espacio, reubicar el split_result
            if (node->count < M - 1)
                relocate(node, split_result->key, split_result->right_tree);
                // caso, dividir y retornar el nuevo nodo al antecesor
            else if (M % 2 == 0)
                return split_par(node, split_result->key, split_result->right_tree);
            else
                return split_impar(node, split_result->key, split_result->right_tree);
        }
    }
    return nullptr;
}

template<typename TK>
void BTree<TK>::relocate(btreeNode<TK> *&node, TK key, btreeNode<TK> *key_right_tree){
    int i = node->count - 1;
    // se  mueve las keys para dejar espacio para la nueva key
    while (i >= 0 && key < node->keys[i]) {
        node->keys[i + 1] = node->keys[i];
        node->children[i + 2] = node->children[i + 1];
        i--;
    }
    i++;
    node->keys[i] = key;
    node->children[i + 1] = key_right_tree;
    node->count++;
}

template<typename TK>
btreeNode<TK>* BTree<TK>::generate_right_node(btreeNode<TK> *&node, int from){
    btreeNode<TK> *right_node = new btreeNode<TK>(M, node->leaf);
    // copiar llaves e hijos desde el nodo original
    int i = from, j = 0;
    while (i < M - 1) // recordar que el nodo esta lleno
    {
        right_node->keys[j] = node->keys[i];
        right_node->children[j] = node->children[i];
        i++;
        j++;
    }
    right_node->children[j] = node->children[i];
    right_node->count = j;
    return right_node;
}

template<typename TK>
SplitResult<TK>* BTree<TK>::split_par(btreeNode<TK>* &node, TK key, btreeNode<TK> *key_right_tree){
    // calcular el elemento central
    int m = (M - 1) / 2;
    TK middle = node->keys[m];
    // crear nodo derecho desde m+1
    btreeNode<TK> *right_node = generate_right_node(node, m + 1);
    // actualizar la cantidad de elementos del nodo
    node->count = m;
    // insertar la key en el lado respectivo
    if (key < middle)
        relocate(node, key, key_right_tree);
    else
        relocate(right_node, key, key_right_tree);
    // retornar el elemento central y el nodo derecho
    return new SplitResult<TK>(middle, right_node);
}

template<typename TK>
SplitResult<TK>* BTree<TK>::split_impar(btreeNode<TK>* &node, TK key, btreeNode<TK> *key_right_tree){
    btreeNode<TK> *right_node;
    TK middle;
    // calcular el elemento central correctamente
    int m = (M - 1) / 2;
    if (key > node->keys[m])
    {
        right_node = generate_right_node(node, m + 1);
        middle = node->keys[m];
        node->count = m;
        relocate(right_node, key, key_right_tree);
    }
    else
    {
        m = m - 1;
        right_node = generate_right_node(node, m + 1);
        if (key < node->keys[m])
        {
            middle = node->keys[m];
            node->count = m;
            relocate(node, key, key_right_tree);
        }
        else
        { // en caso que la llave a insertar ocupe la mitad
            middle = key;
            node->count = m + 1;
            right_node->children[0] = key_right_tree;
        }
    }
    // retornar el elemento central y el nodo derecho
    return new SplitResult<TK>(middle, right_node);
}


template<typename TK>
int BTree<TK>::height(btreeNode<TK>* node){
    if (node == nullptr){
        return -1;
    }else{
        return 1 + height(node->children[0]);
    }
}

template<typename TK>
string BTree<TK>::toString(btreeNode<TK>* node, const string& sep){
    string result = "";
    root->toString(result, sep);
    return result.substr(0,result.size()-sep.length());
}

template<typename TK>
TK BTree<TK>::minKey(btreeNode<TK>* node){
    if(root == nullptr){throw std::out_of_range("Tree is empty");}
    if(node->leaf){
        return node->keys[0];
    }else{
        return minKey(node->children[0]);
    }
}

template<typename TK>
TK BTree<TK>::maxKey(btreeNode<TK>* node){
    if(root == nullptr){throw std::out_of_range("Tree is empty");}
    if(node->leaf){
        return node->keys[node->count - 1];
    }else{
        return maxKey(node->children[node->count]);
    }
}

template<typename TK>
void BTree<TK>::display_pretty(btreeNode<TK>* root){
    if (root == NULL)
        return;
    int i, j, n;
    queue<btreeNode<TK> *> q;
    q.push(root);
    while (!q.empty())
    {
        n = q.size();
        for (i = 0; i < n; i++)
        {
            btreeNode<TK> *node = q.front();
            cout << "<";
            for (j = 0; j < node->count; j++)
                cout << node->keys[j] << " ";
            cout << "> ";
            q.pop();
            if (!node->leaf)
            {
                q.push(node->children[0]);
                for (j = 1; j <= node->count; j++)
                    q.push(node->children[j]);
            }
        }
        cout << endl;
    }
}

#endif //PRAED_BTREE_H
