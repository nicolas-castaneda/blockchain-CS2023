#ifndef IMPLEMENTACION_CIRCULAR_ARRAY_H
#define IMPLEMENTACION_CIRCULAR_ARRAY_H

#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
class CircularArray
{
protected:
    T *array;
    int capacity;
    int back, front;

public:
    CircularArray();
    CircularArray(int _capacity);
    virtual ~CircularArray();

    void redimensionar();

    void push_front(T data);
    void push_back(T data);
    void insert(T data, int pos);

    T pop_front();
    T pop_back();

    bool is_full();
    bool is_empty();

    int size();
    void clear();

    T &operator[](int);
    T get(int);

    void sort();
    bool is_sorted();

    void reverse();

    string to_string(string sep=" ");

private:
    int next(int);
    int prev(int);

    void quicksort(int begin, int end);
    int partition(int begin, int end);
};

template<typename T>
int CircularArray<T>::partition(int begin, int end){
    T pivot = this->array[end];
    int indice_particion = begin;

    for (int i = begin; i != end; i=this->next(i)) {
        if(this->array[i] < pivot){
            swap(this->array[i], this->array[indice_particion]);
            indice_particion = this->next(indice_particion);
        }
    }

    swap(this->array[indice_particion], this->array[end]);
    return indice_particion;
}

template<typename T>
void CircularArray<T>::quicksort(int begin, int end){
    if(begin<end){
        int ubicacion_pivote = partition(begin, end);
        quicksort(begin, ubicacion_pivote-1);
        quicksort(ubicacion_pivote+1, end);
    }
}

template<typename T>
void CircularArray<T>::sort(){
    if(this->front > this->back){
        T* new_array = new T[this->capacity];
        int ind = 0;
        for (int i = this->front; i != this->back; i=this->next(i)) {
            new_array[ind]=this->array[i];
            ind++;
        }
        new_array[ind]=this->array[this->back];
        this->back=this->size() - 1;
        this->front=0;
        delete[] this->array;
        this->array = new_array;
    }
    quicksort(this->front, this->back);
}

template<typename T>
void CircularArray<T>::reverse(){
    int inicio = this->front;
    int fin = this->back;
    if(this->size() % 2 != 0){
        while(abs(inicio - fin) != 0){
            int tmp = this->array[inicio];
            this->array[inicio] = this->array[fin];
            this->array[fin] = tmp;
            inicio = this->next(inicio);
            fin= this->prev(fin);
        }
    }else{
        while(this->next(inicio) != fin){
            int tmp = this->array[inicio];
            this->array[inicio] = this->array[fin];
            this->array[fin] = tmp;
            inicio = this->next(inicio);
            fin= this->prev(fin);
        }
        int tmp = this->array[inicio];
        this->array[inicio] = this->array[fin];
        this->array[fin] = tmp;
    }
}

template<typename T>
bool CircularArray<T>::is_sorted(){
    for (int i = this->front; i != this->back; i=this->next(i)) {
        if(this->array[i] > this->array[this->next(i)]){
            return false;
        }
    }
    return true;
}

template<typename T>
T& CircularArray<T>::operator[](int pos){
    return this->array[(this->front + pos) % this->capacity];
}

template<typename T>
T CircularArray<T>::get(int pos){
    return this->array[(this->front + pos) % this->capacity];
}

template<typename T>
void CircularArray<T>::redimensionar(){
    if(this->capacity!=0){
        int new_capacity = this->capacity*2;
        T* new_array = new T[new_capacity];
        int indice = 0;
        for (int i = this->front; i != this->back; i=next(i)) {
            new_array[indice] = this->array[i];
            indice++;
        }
        new_array[indice] = this->array[back];
        this->back = this->size()-1;
        this->front = 0;
        this->capacity = new_capacity;
        delete[] this->array;
        this->array = new_array;
    }else{
        this->capacity = 4;
        delete[] this->array;
        this->array = new T[this->capacity];
    }
}

template <class T>
bool CircularArray<T>::is_full()
{
    if((this->front == 0 && this->back == this->capacity - 1) || (this->front - 1 == this->back) || this->capacity == 0){
        return true;
    }
    return false;
}

template <class T>
bool CircularArray<T>::is_empty()
{
    if((front == -1 && back == -1)){
        return true;
    }
    return false;
}

template <class T>
int CircularArray<T>::size()
{
    if(front == -1 && back == -1){
        return 0;
    }else if(front <= back){
        return back-front+1;
    }else{
        return (back + 1 + capacity - front);
    }
}

template <class T>
void CircularArray<T>::clear()
{
    delete[] this->array;
    this->array = new T[this->capacity];
    this->front = this->back = -1;

}

template <class T>
void CircularArray<T>::push_front(T data)
{
    if(!this->is_full()){
        if(this->front == -1 || this->back == -1){
            this->front = this->back = 0;
        }else{
            this->front = prev(this->front);
        }
        this->array[this->front] = data;
    }else{
        this->redimensionar();
        this->push_front(data);
    }
}

template <class T>
void CircularArray<T>::push_back(T data)
{
    if(!this->is_full()){
        if(this->front == -1 || this->back == -1){
            this->front = this->back = 0;
        }else{
            this->back = next(this->back);
        }
        this->array[this->back] = data;
    }else{
        this->redimensionar();
        this->push_back(data);
    }
}

template <class T>
void CircularArray<T>::insert(T data, int pos)
{
    if(pos >= 0 && pos <= this->size()){
        if(pos==0){
            this->push_front(data);
        }else if(pos==size()){
            this->push_back(data);
        }else{
            if(!this->is_full()){
                T* new_array = new T[this->capacity];
                int ind = 0;
                for (int i = this->front; i != this->back; i=this->next(i)) {
                    if(ind == pos){
                        new_array[ind]=data;
                        ind++;
                        new_array[ind]=this->array[i];
                    }else{
                        new_array[ind]=this->array[i];
                    }
                    ind++;
                }
                if(ind == pos){
                    new_array[ind]=data;
                    ind++;
                }
                new_array[ind]=this->array[this->back];
                this->back=this->size();
                this->front=0;
                delete[] this->array;
                this->array = new_array;
            }else{
                this->redimensionar();
                this->insert(data, pos);
            }
        }
    }

}

template <class T>
T CircularArray<T>::pop_back()
{
    if(!this->is_empty()){
        int elem = array[this->back];
        if(this->front == this->back){
            this->front = this->back = -1;
        }else{
            this->back = prev(this->back);
        }
        return elem;
    }
    return -1;
}

template <class T>
T CircularArray<T>::pop_front()
{
    if(!this->is_empty()){
        int elem = array[this->front];
        if(this->front == this->back){
            this->front = this->back = -1;
        }else{
            this->front = next(this->front);
        }
        return elem;
    }
    return -1;
}

template <class T>
CircularArray<T>::CircularArray()
{
    this->array = new T[0];
    this->capacity = 0;
    this->front = this->back = -1;

}

template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
    this->array = new T[_capacity];
    this->capacity = _capacity;
    this->front = this->back = -1;
}

template <class T>
CircularArray<T>::~CircularArray()
{
    delete[] array;
}

template <class T>
int CircularArray<T>::prev(int index)
{
    return (index == 0) ? capacity - 1 : index - 1;
}

template <class T>
int CircularArray<T>::next(int index)
{
    return (index + 1) % capacity;
}

template <class T>
string CircularArray<T>::to_string(string sep)
{
    string result = "";
    for (int i = 0; i < size(); i++)
        result += std::to_string((*this)[i]) + sep;
    return result;
}

#endif //IMPLEMENTACION_CIRCULAR_ARRAY_H