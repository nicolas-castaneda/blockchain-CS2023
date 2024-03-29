//
// Created by nick_cq on 01/12/22.
//

#ifndef PRAED_APP_H
#define PRAED_APP_H

#include "blockchain.h"
#include <fstream>
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using Data = float;

void print_main_menu(){
    std::cout<<"Menu principal"<<std::endl;
    std::cout<<"1. Print chain"<<std::endl;
    std::cout<<"2. Add"<<std::endl;
    std::cout<<"3. Modify"<<std::endl;
    std::cout<<"4. Remove"<<std::endl;
    std::cout<<"5. Query"<<std::endl;
    std::cout<<"6. Exit"<<std::endl;
}


void print_chain(Blockchain<Data> *& chain){
    char stop;
    chain->print_chain();
    cout<<"Continuar:"<<endl;
    cin>>stop;
}

void add_chain(Blockchain<Data> *& chain){
    char stop;
    string sender, receiver;
    Data data;

    cout<<"Sender:";
    cin>>sender;

    cout<<"Receiver:";
    cin>>receiver;

    cout<<"Data:";
    cin>>data;

    chain->insert(new Transaction<Data>(sender,receiver,data));
    cout<<"Continuar:"<<endl;
    cin>>stop;
}

void modify_chain(Blockchain<Data> *& chain){
    char stop;
    string sender, receiver;
    Data data;
    int index;

    cout<<"Sender:";
    cin>>sender;

    cout<<"Receiver:";
    cin>>receiver;

    cout<<"Data:";
    cin>>data;

    cout<<"Block index:";
    cin>>index;

    chain->modify(index, new Transaction<Data>(sender,receiver,data));
    cout<<"Informacion agregada en bloque cerrado - "<<"Sender: "<<sender<<", Receiver: "<<receiver<<" Data"<<data<<endl;
    cout<<"Continuar:"<<endl;
    cin>>stop;
}

void print_query_menu(){
    std::cout<<"Menu Query"<<std::endl;

    std::cout<<"1. Sender Equal to"<<std::endl;
    std::cout<<"2. Sender Total Receivers"<<std::endl;
    std::cout<<"3. Sender Total Data sent"<<std::endl;

    std::cout<<"4. Receiver Equal to"<<std::endl;
    std::cout<<"5. Receiver Total Senders"<<std::endl;
    std::cout<<"6. Receiver Total Data received"<<std::endl;

    std::cout<<"7. Data Equal to"<<std::endl;
    std::cout<<"8. Max Data"<<std::endl;
    std::cout<<"9. Min Data"<<std::endl;
    std::cout<<"10. Range Data"<<std::endl;
    std::cout<<"11. Return"<<std::endl;
}

void sender_equal_to(Blockchain<Data> *& chain){
    char stop;

    string sender;
    cout<<"Sender equal to:";
    cin>>sender;

    cout<<chain->sender_equal_to(sender)<<endl;

    cout<<"Continuar:"<<endl;
    cin>>stop;
}

void receiver_equal_to(Blockchain<Data> *& chain){
    char stop;

    string receiver;
    cout<<"Receiver equal to:";
    cin>>receiver;

    cout<<chain->receiver_equal_to(receiver)<<endl;

    cout<<"Continuar:"<<endl;
    cin>>stop;
}

void data_equal_to(Blockchain<Data> *& chain){
    char stop;

    Data data;
    cout<<"Data equal to:";
    cin>>data;

    cout<<chain->data_equal_to(data)<<endl;

    cout<<"Continuar:"<<endl;
    cin>>stop;
}

void max_data(Blockchain<Data> *& chain){
    char stop;

    cout<<chain->get_max_transaction()<<endl;

    cout<<"Continuar:"<<endl;
    cin>>stop;
}

void min_data(Blockchain<Data> *& chain){
    char stop;

    cout<<chain->get_min_transaction()<<endl;

    cout<<"Continuar:"<<endl;
    cin>>stop;
}

void range_data(Blockchain<Data> *& chain){
    char stop;

    Data min;
    cout<<"Min equal to:";
    cin>>min;

    Data max;
    cout<<"Max equal to:";
    cin>>max;
    cout<<chain->get_range_transaction(min,max)<<endl;

    cout<<"Continuar:"<<endl;
    cin>>stop;
}

void sender_total_receivers(Blockchain<Data> *& chain){
    char stop;

    string sender;
    cout<<"Sender equal to:";
    cin>>sender;

    cout<<"# Receivers: ";
    cout<<chain->sender_total_receivers(sender)<<endl;

    cout<<"Continuar:"<<endl;
    cin>>stop;
}

void sender_total_data_sent(Blockchain<Data> *& chain){
    char stop;

    string sender;
    cout<<"Sender equal to:";
    cin>>sender;

    cout<<"Data amount: ";
    cout<<chain->sender_total_data_sent(sender)<<endl;

    cout<<"Continuar:"<<endl;
    cin>>stop;
}

void receiver_total_senders(Blockchain<Data> *& chain){
    char stop;

    string receiver;
    cout<<"Receiver equal to:";
    cin>>receiver;

    cout<<"# Receivers: ";
    cout<<chain->receiver_total_senders(receiver)<<endl;

    cout<<"Continuar:"<<endl;
    cin>>stop;
}

void receiver_total_data_received(Blockchain<Data> *& chain){
    char stop;

    string receiver;
    cout<<"Receiver equal to:";
    cin>>receiver;

    cout<<"Data amount: ";
    cout<<chain->receiver_total_data_received(receiver)<<endl;

    cout<<"Continuar:"<<endl;
    cin>>stop;
}

void query_chain(Blockchain<Data> *& chain){
    int opcion = 0;
    while(1){
        print_query_menu();
        cout<<"Ingrese su opcion: ";
        cin>>opcion;
        if (opcion == 1){
            sender_equal_to(chain);
        } else if (opcion == 2){
            sender_total_receivers(chain);
        } else if (opcion == 3){
            sender_total_data_sent(chain);
        } else if (opcion == 4){
            receiver_equal_to(chain);
        } else if (opcion == 5){
            receiver_total_senders(chain);
        } else if (opcion == 6) {
            receiver_total_data_received(chain);
        } else if (opcion == 7) {
            data_equal_to(chain);
        } else if (opcion == 8) {
            max_data(chain);
        } else if (opcion == 9) {
            min_data(chain);
        } else if (opcion == 10) {
            range_data(chain);
        } else{
            break;
        }
    }
}

void print_remove_menu(){
    std::cout<<"Menu Remove"<<std::endl;
    std::cout<<"1. Remove Index Sender"<<std::endl;
    std::cout<<"2. Remove Index Receiver"<<std::endl;
    std::cout<<"3. Remove Data"<<std::endl;
    std::cout<<"4. Return"<<std::endl;
}

void remove_sender(Blockchain<Data> *& chain){
    char stop;

    string sender;
    cout<<"Sender to delete:";
    cin>>sender;

    chain->remove_index_sender(sender);

    cout<<"Continuar:"<<endl;
    cin>>stop;
}

void remove_receiver(Blockchain<Data> *& chain){
    char stop;

    string receiver;
    cout<<"Receiver to delete:";
    cin>>receiver;

    chain->remove_index_receiver(receiver);

    cout<<"Continuar:"<<endl;
    cin>>stop;
}

void remove_index_data(Blockchain<Data> *& chain){
    char stop;

    Data data;
    cout<<"Data to delete:";
    cin>>data;

    chain->remove_index_data(data);

    cout<<"Continuar:"<<endl;
    cin>>stop;
}

void remove_min_data(Blockchain<Data> *& chain){
    char stop;

    chain->remove_max_data();

    cout<<"Continuar:"<<endl;
    cin>>stop;
}

void remove_max_data(Blockchain<Data> *& chain){
    char stop;

    chain->remove_min_data();

    cout<<"Continuar:"<<endl;
    cin>>stop;
}

void print_remove_data_menu(){
    std::cout<<"Menu Remove"<<std::endl;
    std::cout<<"1. Remove Index Data"<<std::endl;
    std::cout<<"2. Remove Max Data"<<std::endl;
    std::cout<<"3. Remove Min Data"<<std::endl;
    std::cout<<"4. Return"<<std::endl;
}

void remove_data(Blockchain<Data> *& chain){

    int opcion = 0;
    while(1){
        print_remove_data_menu();
        cout<<"Ingrese su opcion: ";
        cin>>opcion;
        if (opcion == 1){
            remove_index_data(chain);
        } else if (opcion == 2){
            remove_max_data(chain);
        } else if (opcion == 3){
            remove_min_data(chain);
        } else{
            break;
        }
    }
}

void remove_chain(Blockchain<Data> *& chain){
    int opcion = 0;
    while(1){
        print_remove_menu();
        cout<<"Ingrese su opcion: ";
        cin>>opcion;
        if (opcion == 1){
            remove_sender(chain);
        } else if (opcion == 2){
            remove_receiver(chain);
        } else if (opcion == 3){
            remove_data(chain);
        } else{
            break;
        }
    }
}

void App(){
    Blockchain<Data> * chain = new Blockchain<Data>();
    string sender, receiver;
    Data data;
    ifstream file("../transactions100.txt");
    while(file >> sender >> receiver >> data){
        chain->insert(new Transaction<Data>(sender,receiver,data));
    }

    int opcion = 0;
    while(1){
        print_main_menu();
        cout<<"Ingrese su opcion: ";
        cin>>opcion;
        if (opcion == 1){
            print_chain(chain);
        } else if (opcion == 2){
            add_chain(chain);
        } else if (opcion == 3){
            modify_chain(chain);
        } else if (opcion == 4){
            remove_chain(chain);
        } else if (opcion == 5){
            query_chain(chain);
        } else {
            break;
        }
    }

}

#endif //PRAED_APP_H
