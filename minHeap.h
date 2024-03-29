#ifndef MINHEAP_H
#define MINHEAP_H

#include "heapNode.h"

// * Start heap:

template <typename T>
class minHeap{
private:
    static int left(int index){return index*2 +1;};
    static int right(int index){return index*2 +2;};
    static int parent(int index){return (index-1)/2;};

    static void heapify_down(vector<T>&vec, int p){
        if (left(p) > vec.size()-1){
            return;
        }
        if (right(p) > vec.size()-1 && left(p)< vec.size()){
            if (vec[p] > vec[left(p)] ){ // *here
            T temp = vec[p];
            T val = vec[left(p)];
            vec[p] = val;
            vec[left(p)] = temp;
            }      
        }else {            
        if (vec[p] > vec[left(p)] || vec[p] > vec[right(p)]){ // *here
            T temp = vec[p];
            T val = min(vec[left(p)], vec[right(p)]); // *here
            vec[p] = val;
            
            if (vec[left(p)] == val){
                vec[left(p)] = temp;
                heapify_down(vec, left(p));
            }else{
                vec[right(p)] = temp;
                heapify_down(vec, right(p));
            }
            }      
        }
    }
    static void heapify_up(vector<T>& vec, int p){
        
        int par = parent(p);
        if ( par >= 0){
            // cout << "p:" << p << "|| par:" << par <<"\n";
            if (vec[p] < vec[par]){
                swap(vec[par], vec[p]);
                heapify_up(vec, par);
            }
        }        
    }
    vector<T> elements;
public:
    minHeap() = default;
    
    void push(T data){
        elements.push_back(data);
        heapify_up(elements, elements.size() - 1);
    }
    T pop(){
        T temp = elements[0]; // *
        elements[0] = elements[elements.size() - 1];
        elements.pop_back();
        heapify_down(elements, 0);
        return temp; // *
    }

    static void build_from(vector<T> & vec){
        int len = vec.size();
        for (int i=(len/2)-1;i>=0;--i){
            heapify_down(vec, i);
        }
    }
    void display(){
        for (auto i: elements)
            cout << i << " ";
        cout <<endl;
    }
    DoubleList<T> get_value(){
        DoubleList<T> result;
        T min = this->pop();
        result.push_back(min);
        while (min == elements[0]){
            min = this->pop();
            result.push_back(min);
        }
        for (auto i=result.begin(); i != result.end(); ++i)
            this->push(*i);
        return result;
    }
};

// * End heap

#endif // MINHEAP_H