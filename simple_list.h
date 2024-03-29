//
// Created by Nicolas on 22/11/2022.
//

#ifndef PRAED_SIMPLE_LIST_H
#define PRAED_SIMPLE_LIST_H
template<typename T>
struct ListNode
{
    T data;
    ListNode* next;
};


template<typename T>
void push(ListNode<T>* &head, T d){
    auto* nodo = new ListNode<T>;
    nodo->data = d;
    nodo->next = head;
    head = nodo;
}
template<typename T>
void display(ListNode<T>* head){
    while(head != nullptr){
        std::cout<<head->data<<"->";
        head = head -> next;
    }
    std::cout<<std::endl;
}

/* SET */
#endif //PRAED_SIMPLE_LIST_H
