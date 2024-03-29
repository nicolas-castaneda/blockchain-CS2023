#include <utility>

#include <ctime>
#include <chrono>

#include "block.h"
#include "datastructures.h"
template<typename Data=int>
class Blockchain {
private:
    // mutables
    CircularArray<Block<Data>*> blockchain;
    int size{}; // size of blockchain

    // fixed
    int precision{};
    int max_transactions{};

    ChainHash<std::string, DoubleList<std::pair<int,int>>> hash_sender;
    ChainHash<std::string, DoubleList<std::pair<int,int>>> hash_receiver;
    ChainHash<Data, DoubleList<std::pair<int,int>>> hash_data;
    maxHeap<heapNode<Data>> maxHeap_data; //* A
    minHeap<heapNode<Data>> minHeap_data; //* A
    BTree<btreePairNode<Data>> btree_data = BTree<btreePairNode<Data>>(4); //* A
    
public:
    // CHANGE TO ARRAY
    Blockchain(){
        auto genesis = new Block<Data>("000", 0);
        this->precision = 3;
        this->max_transactions = 4;
        this->size = 1;

        auto current = new Block<Data>(this->max_transactions);

        current->set_prev_hash(genesis->get_hash());

        current->set_precision(this->precision);

        this->blockchain.push_back(genesis);
        this->blockchain.push_back(current);
    };

    void insert_data_structures(std::string sender, std::string receiver, Data data, int block_number, int transaction_number){
        // hash
        if(!this->hash_sender.find(sender)) {this->hash_sender.insert(sender,DoubleList<std::pair<int,int>>());}
        this->hash_sender[sender].push_back(std::make_pair(block_number, transaction_number));
        if(!this->hash_receiver.find(receiver)) {this->hash_receiver.insert(receiver,DoubleList<std::pair<int,int>>());}
        this->hash_receiver[receiver].push_back(std::make_pair(block_number, transaction_number));
        if(!this->hash_data.find(data)) {this->hash_data.insert(data,DoubleList<std::pair<int,int>>());}
        this->hash_data[data].push_back(std::make_pair(block_number, transaction_number));

        // * max_heap
        pair<int, int> pos;
        pos.first = block_number;
        pos.second = transaction_number;

        heapNode<Data> hp(data, pos);
        this->maxHeap_data.push(hp);

        // * min_heap
        this->minHeap_data.push(hp);

        // * btree
        btreePairNode<Data> bt;
        bt.first = data;
        if(!btree_data.search(bt)){ bt.second = DoubleList<std::pair<int,int>>(); btree_data.insert(bt);}
        btree_data.get(bt).second.push_back(pos);

    }

    // insert must accept a class Transaction with his elements
    void insert(Transaction<Data>* transaction){
        Block<Data>* current = this->blockchain[this->size];
        int block_number = this->size;
        int transaction_number = current->get_size() ;
        auto [sender, receiver, data] = transaction->parse();

        current->add_transaction(transaction);

        if (current->get_size() == this->max_transactions){

            auto prev_hash = current->get_hash();

            this->blockchain.push_back(new Block<Data>(this->max_transactions));
            this->size++;

            current = this->blockchain[this->size];

            current->set_prev_hash(prev_hash);
            current->set_precision(this->precision);
        }

        // insert to data structures
        insert_data_structures(sender, receiver, data, block_number, transaction_number);
    }

    // cascade function starts when a transaction tried to be added into the blockchain
    void modify(int indx, Transaction<Data>* transaction){
        if (indx > this->size) return;

        auto temp = this->blockchain[indx];

        int block_number = indx;
        int transaction_number =  temp->get_size();
        auto [sender, receiver, data] = transaction->parse();
        insert_data_structures(sender, receiver, data, block_number, transaction_number);

        temp->set_max_transactions(this->max_transactions + 1);
        temp->add_transaction(transaction);

        auto new_prev_hash = temp->mine();

        int n=0;
        // Modified until last block
        while(indx <= this->size){
            temp = this->blockchain[indx];

            temp->set_prev_hash(new_prev_hash);
            temp->mine();
            new_prev_hash = temp->get_hash();
            n++;
            indx++;
        }

        std::cout << "Cantidad de Bloques Modificados: " << n <<std::endl;
    }

    // Iterate over all blocks, print data
    void print_chain(){
        int n = 1;

        while (n <= this->size) {
            Block<Data> * temp = this->blockchain[n];
            std::cout << "Block # " << n << ": "<< std::endl;
            std::cout << "Hash: " << temp->get_hash() << std::endl;
            std::cout << "Prev Hash: " << temp->get_prev_hash() << std::endl;
            std::cout << "Transactions: " << temp->get_transactions() << std::endl;
            std::cout << "Nonce: " << temp->get_nonce() << std::endl;
            std::cout << "Size: " << temp->get_size() << std::endl;
            std::cout << "----------------" << std::endl;
            n++;
        }
    }

    int size_block() const{
        return this->size;
    }

    template<typename T>
    typename std::enable_if<!std::is_arithmetic<T>::value, std::string>::type test(T value)
    {
        std::string v;
        v = std::string(value);
        return v;
    }

    std::string sender_equal_to(std::string value){

        auto start = std::chrono::steady_clock::now();

        std::string transactions = "";
        DoubleList<std::pair<int,int>> indexes;
        if (hash_sender.find(value)) indexes = hash_sender[value];

        for(auto index = indexes.begin(); index != indexes.end(); ++index){
            int block_index = (*index).first;
            int transaction_index = (*index).second;

            Block<Data>* block = this->blockchain[block_index];
            Transaction<Data>* transaction = block->get_transaction(transaction_index);

            transactions += transaction->get_information() ;
        }

        auto end = std::chrono::steady_clock::now();
        cout<< "Tiempo de ejecucion en ms: "<<chrono::duration_cast<chrono::microseconds>(end-start).count()<<endl;

        return transactions;
    }

    std::string sender_equal_to_lineal(std::string value){
        string transactions;

        auto start = std::chrono::steady_clock::now();

        for (int i=1; i < blockchain.size() ; ++i){

            Block<Data>* block = this->blockchain[i];
            for(int j=0; j < block->transactions.size(); j++){
                Transaction<Data>* transaction = block->get_transaction(j);
                if(transaction->get_sender() == value){
                    transactions += transaction->get_information();
                }
            }
        }

        auto end = std::chrono::steady_clock::now();
        cout<< "Tiempo de ejecucion en ms: "<<chrono::duration_cast<chrono::microseconds>(end-start).count()<<endl;

        return transactions;
    }

    int sender_total_receivers(std::string value){
        DoubleList<std::pair<int,int>> indexes;
        auto start = std::chrono::steady_clock::now();

        if (hash_sender.find(value)) indexes = hash_sender[value];

        auto end = std::chrono::steady_clock::now();
        cout<< "Tiempo de ejecucion en ms: "<<chrono::duration_cast<chrono::microseconds>(end-start).count()<<endl;

        return indexes.size();
    }

    Data sender_total_data_sent(std::string value){
        Data transactions = 0;
        DoubleList<std::pair<int,int>> indexes;

        auto start = std::chrono::steady_clock::now();

        if (hash_sender.find(value)) indexes = hash_sender[value];

        for(auto index = indexes.begin(); index != indexes.end(); ++index){
            int block_index = (*index).first;
            int transaction_index = (*index).second;

            Block<Data>* block = this->blockchain[block_index];
            Transaction<Data>* transaction = block->get_transaction(transaction_index);

            transactions += transaction->get_data() ;
        }

        auto end = std::chrono::steady_clock::now();
        cout<< "Tiempo de ejecucion en ms: "<<chrono::duration_cast<chrono::microseconds>(end-start).count()<<endl;

        return transactions;
    }

    std::string receiver_equal_to(std::string value){
        std::string transactions = "";
        DoubleList<std::pair<int,int>> indexes;

        auto start = std::chrono::steady_clock::now();

        if (hash_receiver.find(value)) indexes = hash_receiver[value];

        for(auto index = indexes.begin(); index != indexes.end(); ++index){
            int block_index = (*index).first;
            int transaction_index = (*index).second;

            Block<Data>* block = this->blockchain[block_index];
            Transaction<Data>* transaction = block->get_transaction(transaction_index);

            transactions += transaction->get_information() ;
        }

        auto end = std::chrono::steady_clock::now();
        cout<< "Tiempo de ejecucion en ms: "<<chrono::duration_cast<chrono::microseconds>(end-start).count()<<endl;

        return transactions;
    }

    int receiver_total_senders(std::string value){
        DoubleList<std::pair<int,int>> indexes;

        auto start = std::chrono::steady_clock::now();

        if (hash_receiver.find(value)) indexes = hash_receiver[value];

        auto end = std::chrono::steady_clock::now();
        cout<< "Tiempo de ejecucion en ms: "<<chrono::duration_cast<chrono::microseconds>(end-start).count()<<endl;

        return indexes.size();
    }

    Data receiver_total_data_received(std::string value){
        Data transactions = 0;
        DoubleList<std::pair<int,int>> indexes;

        auto start = std::chrono::steady_clock::now();

        if (hash_receiver.find(value)) indexes = hash_receiver[value];

        for(auto index = indexes.begin(); index != indexes.end(); ++index){
            int block_index = (*index).first;
            int transaction_index = (*index).second;

            Block<Data>* block = this->blockchain[block_index];
            Transaction<Data>* transaction = block->get_transaction(transaction_index);

            transactions += transaction->get_data() ;
        }

        auto end = std::chrono::steady_clock::now();
        cout<< "Tiempo de ejecucion en ms: "<<chrono::duration_cast<chrono::microseconds>(end-start).count()<<endl;

        return transactions;
    }

    void remove_index_sender(std::string sender){
        hash_sender.remove(sender);
        hash_receiver;
    }

    void remove_index_receiver(std::string receiver){
        hash_receiver.remove(receiver);
    }

    void remove_index_data(Data data){
        hash_data.remove(data);
        btreePairNode<Data> del;
        del.first = data;
        btree_data.remove(del);
    }

    void remove_max_data(){
        maxHeap_data.pop(); //* A
    }

    void remove_min_data(){
        minHeap_data.pop(); //* A
    }

    template<typename DataType>
    std::string data_equal_to(const DataType value){
        std::string transactions = "";
        DoubleList<std::pair<int,int>> indexes;

        auto start = std::chrono::steady_clock::now();

        if (hash_data.find(value)) indexes = hash_data[value];

        for(auto index = indexes.begin(); index != indexes.end(); ++index){
            int block_index = (*index).first;
            int transaction_index = (*index).second;

            Block<Data>* block = this->blockchain[block_index];
            Transaction<Data>* transaction = block->get_transaction(transaction_index);

            transactions += transaction->get_information() ;
        }

        auto end = std::chrono::steady_clock::now();
        cout<< "Tiempo de ejecucion en ms: "<<chrono::duration_cast<chrono::microseconds>(end-start).count()<<endl;

        return transactions;
    }

    // * get_max_transaction
    //template<typename DataType>
    std::string get_max_transaction(){
        string transactions;
        DoubleList<heapNode<Data>> indexes = maxHeap_data.get_value();

        auto start = std::chrono::steady_clock::now();

        for (auto i=indexes.begin(); i != indexes.end(); ++i){
            int block_index = (*i).second.first;
            int transaction_index = (*i).second.second;

            Block<Data>* block = this->blockchain[block_index];
            Transaction<Data>* transaction = block->get_transaction(transaction_index);
            transactions += transaction->get_information();
        }

        auto end = std::chrono::steady_clock::now();
        cout<< "Tiempo de ejecucion en ms: "<<chrono::duration_cast<chrono::microseconds>(end-start).count()<<endl;

        return transactions;
    }

    std::string get_max_transaction_lineal(){
        string transactions;

        auto start = std::chrono::steady_clock::now();
        int max = -1;

        for (int i=1; i < blockchain.size() ; ++i){

            Block<Data>* block = this->blockchain[i];
            for(int j=0; j < block->transactions.size(); j++){
                Transaction<Data>* transaction = block->get_transaction(j);
                if(transaction->get_data() > max){
                    transactions.clear();
                    max = transaction->get_data();
                    transactions += transaction->get_information();
                }
            }
        }

        auto end = std::chrono::steady_clock::now();
        cout<< "Tiempo de ejecucion en ms: "<<chrono::duration_cast<chrono::microseconds>(end-start).count()<<endl;

        return transactions;
    }

    // * get_min_transaction
    //template<typename DataType>
    std::string get_min_transaction(){
        string transactions;

        auto start = std::chrono::steady_clock::now();

        DoubleList<heapNode<Data>> indexes = minHeap_data.get_value();
        for (auto i=indexes.begin(); i != indexes.end(); ++i){
            int block_index = (*i).second.first;
            int transaction_index = (*i).second.second;

            Block<Data>* block = this->blockchain[block_index];
            Transaction<Data>* transaction = block->get_transaction(transaction_index);
            transactions += transaction->get_information();
        }

        auto end = std::chrono::steady_clock::now();
        cout<< "Tiempo de ejecucion en ms: "<<chrono::duration_cast<chrono::microseconds>(end-start).count()<<endl;

        return transactions;
    }

    std::string get_min_transaction_lineal(){
        string transactions;

        auto start = std::chrono::steady_clock::now();
        int min = INT32_MAX;

        for (int i=1; i < blockchain.size() ; ++i){

            Block<Data>* block = this->blockchain[i];
            for(int j=0; j < block->transactions.size(); j++){
                Transaction<Data>* transaction = block->get_transaction(j);
                if(transaction->get_data() < min){
                    transactions.clear();
                    min = transaction->get_data();
                    transactions += transaction->get_information();
                }
            }
        }

        auto end = std::chrono::steady_clock::now();
        cout<< "Tiempo de ejecucion en ms: "<<chrono::duration_cast<chrono::microseconds>(end-start).count()<<endl;

        return transactions;
    }

    // * get_range_transaction
    std::string get_range_transaction(Data min, Data max){
        string transactions;
        DoubleList<std::pair<int,int>> indexes = btree_data.get_range(min, max);

        auto start = std::chrono::steady_clock::now();

        for(auto index = indexes.begin(); index != indexes.end(); ++index){
            int block_index = (*index).first;
            int transaction_index = (*index).second;

            Block<Data>* block = this->blockchain[block_index];
            Transaction<Data>* transaction = block->get_transaction(transaction_index);

            transactions += transaction->get_information() ;
        }

        auto end = std::chrono::steady_clock::now();
        cout<< "Tiempo de ejecucion en ms: "<<chrono::duration_cast<chrono::microseconds>(end-start).count()<<endl;

        return transactions;
    }

    std::string get_range_transaction_lineal(Data min, Data max){
        string transactions;

        auto start = std::chrono::steady_clock::now();

        for (int i=1; i < blockchain.size() ; ++i){

            Block<Data>* block = this->blockchain[i];
            for(int j=0; j < block->transactions.size(); j++){
                Transaction<Data>* transaction = block->get_transaction(j);
                if(transaction->get_data() >= min && transaction->get_data() <= max){
                    transactions += transaction->get_information();
                }
            }
        }

        auto end = std::chrono::steady_clock::now();
        cout<< "Tiempo de ejecucion en ms: "<<chrono::duration_cast<chrono::microseconds>(end-start).count()<<endl;

        return transactions;
    }

    ~Blockchain(){
        for(int i=0; i<=size ; i++){
            delete this->blockchain[i];
        }
    }
};