#include "User.hpp"

class Node {
    public:
        User *user;
        Node *next;
        Node(User *user) {
            this->user = user;
        }
};

class SinglyLinkedList {

    private:
        User *head;
        User *tail;
        int elementsCount;
        Node *list;

    public:
        SinglyLinkedList();
        bool isEmpty();
        void insertAtTheBeginning(User *user);
        User* removeAtTheBeginning();
        User* getHead();
        User* getTail();
};
