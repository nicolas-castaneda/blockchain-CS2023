#ifndef IMPLEMENTACION_HASH_CHAINHASH_H
#define IMPLEMENTACION_HASH_CHAINHASH_H

#include <forward_list>

#include <stdexcept>
using namespace std;

const float maxFillFactor = 0.5;
const int maxCollision = 2;

template<typename TK, typename TV>
class ChainHash{
private:

    struct Entry{
        TK key;
        TV value;
        size_t hashcode;
        Entry(TK _k, TV _v, size_t _h){
            key = _k; value = _v; hashcode = _h;
        }

    };

    class ChainHashIterator
    {
    private:
        forward_list<Entry>* array;
        int index;
        typename forward_list<Entry>::iterator bucket_iterator;
        int capacity;
    public:
        ChainHashIterator(forward_list<Entry>* otro, int capacity, bool end){
            this->capacity = capacity;
            this->array = otro;
            if(end){
                this->index = capacity - 1;
                this->bucket_iterator = this->array[this->index].end();
            }else{
                bool done = false;
                int i = 0;
                for (; i < capacity; ++i) {
                    if(!this->array[i].empty()){
                        for(auto it=this->array[i].begin(); it != this->array[i].end(); it++){
                            this->index = i;
                            this->bucket_iterator = it;
                            done = true;
                            break;
                        }
                    }
                    if(done){break;}
                    int index = i;
                    bucket_iterator = this->array[this->index].end();
                }
            }

        }
        ChainHashIterator(const ChainHashIterator& otro){
            this->array = otro.array;
            this->index = otro.index;
            this->bucket_iterator = otro.bucket_iterator;
            this->capacity = otro.capacity;
        }

        std::pair<TK,TV> operator*(){
            return make_pair(bucket_iterator->key, bucket_iterator->value);
        }

        ChainHashIterator& operator++(){
            if (std::next(this->bucket_iterator) != array[index].end()){
                this->bucket_iterator++;
                return *this;
            } else {
                if(index + 1 == this->capacity){
                    this->bucket_iterator = this->array[this->index].end();
                    return *this;
                }else{
                    for (int i = index+1; i < this->capacity; ++i) {
                        if(!this->array[i].empty()){
                            for(auto it=this->array[i].begin(); it != this->array[i].end(); it++){
                                this->bucket_iterator = it;
                                this->index = i;
                                return *this;
                            }
                        }
                    }
                }
            }
            this->bucket_iterator = this->array[this->index].end();
            return *this;
        }

        bool operator!=(const ChainHashIterator& otro){
            return otro.bucket_iterator != this->bucket_iterator;
        }

        ChainHashIterator next(){
            ChainHashIterator iterator = ChainHashIterator(*this);
            ++iterator;
            return iterator;
        }

    };

    forward_list<Entry>* array;
    int capacity; // tamanio del hashtable
    hash<TK> getHash;
public:
    int size; // cantidad de entradas

    bool empty(){
        return this->size == 0;
    }

    ChainHash(int _capacity = 3){
        // TODO: Inicializar el hashtable
        this->capacity = _capacity;
        this->size = 0;
        this->array = new forward_list<Entry>[capacity];
    }

    float fillFactor(){
        return this->size / (this->capacity * maxCollision);
    }

    void insert(TK key, TV value){
        if(fillFactor() >= maxFillFactor) rehashing();

        size_t hashcode =  getHash(key);
        int index = hashcode % capacity;

        // Verificar si la llave existe
        for(auto it=this->array[index].begin(); it != this->array[index].end(); it++){
            if(it->key == key){
                it->value = value;
                return;
            }
        }
        this->size++;

        this->array[index].push_front(Entry(key, value, hashcode));
    }

    void rehashing(){
        // TODO
        auto* new_array = new forward_list<Entry>[this->capacity*2];

        for (int i = 0; i < this->capacity; ++i) {
            if(!this->array[i].empty()){
                for(auto it=this->array[i].begin(); it != this->array[i].end(); it++){
                    int index = it->hashcode % (capacity * 2);
                    new_array[index].push_front(Entry(it->key, it->value, it->hashcode));
                }
            }
        }

        this->capacity = this->capacity * 2;
        delete[] this->array;
        this->array = new_array;
    }

    TV get(TK key){
        // TODO
        size_t hashcode =  getHash(key);
        int index = hashcode % capacity;

        for(auto it=this->array[index].begin(); it != this->array[index].end(); it++){
            if(it->key == key){
                return it->value;
            }
        }
        throw std::invalid_argument("Llave no encontrada");
    }

    bool find(TK key){
        // TODO
        size_t hashcode =  getHash(key);
        int index = hashcode % capacity;

        for(auto it=this->array[index].begin(); it != this->array[index].end(); it++){
            if(it->key == key){
                return true;
            }
        }
        return false;
    }

    void remove(TK key){
        // TODO
        size_t hashcode =  getHash(key);
        int index = hashcode % capacity;

        auto previous = this->array[index].before_begin();
        for(auto it=this->array[index].begin(); it != this->array[index].end(); it++){
            if(it->key == key){
                this->array[index].erase_after(previous);
                this->size--;
                return;
            }
            previous = it;
        }
    }

    int bucket_count(){
        return this->capacity;
    }

    ChainHashIterator begin(){
        return ChainHashIterator(this->array, this->capacity, false);
    }

    ChainHashIterator end(){
        return ChainHashIterator(this->array, this->capacity, true);
    }

    typename forward_list<Entry>::iterator begin(int i_bucket){
        return this->array[i_bucket].begin();
    }

    typename forward_list<Entry>::iterator end(int i_bucket)
    {
        return this->array[i_bucket].end();
    }

    TV& operator [](TK key){
        size_t hashcode =  getHash(key);
        int index = hashcode % capacity;

        for(auto it=this->array[index].begin(); it != this->array[index].end(); it++){
            if(it->key == key){
                return it->value;
            }
        }
        throw std::invalid_argument("Llave no encontrada");
    }

    ~ChainHash(){
        delete[] this->array;
    }
};

#endif //IMPLEMENTACION_HASH_CHAINHASH_H
