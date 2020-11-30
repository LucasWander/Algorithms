#include <iostream>
#include "SinglyLinkedList.hpp"
#include "User.hpp"


SinglyLinkedList::SinglyLinkedList() {
    this->elementsCount = 0;
}

bool SinglyLinkedList::isEmpty() {
    return this->elementsCount == 0;
}


void SinglyLinkedList::insertAtTheBeginning(User *user) {

    this->elementsCount++;

    Node *node = new Node(user);

    this->head = user;
    this->tail = user;

    if(this->isEmpty()){
        this->list = node;
        node->next = nullptr;
    }
    else {
        node->next = this->list;
        this->list = node;
    }



}

User* SinglyLinkedList::removeAtTheBeginning() {
    if(this->isEmpty())
        throw std::underflow_error("You can't remove from a empty list");
    this->elementsCount--;

    Node *aux = this->list;
    User *user = aux->user;

    if(this->list->next == nullptr) {
        this->head = nullptr;
    }
    this->list = this->list->next;
    this->head = this->list->user;


    return user;
}


User* SinglyLinkedList::getHead() {

    if(this->isEmpty())
        throw std::underflow_error("You can't get the head element on a emptylist");

    return this->head;
}


User* SinglyLinkedList::getTail() {
    if(this->isEmpty())
        throw std::underflow_error("You can't get the tail element on a emptylist");

    return this->tail;
}
