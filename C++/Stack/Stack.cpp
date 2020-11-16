#include <iostream>
#include "Stack.hpp"

Stack::Stack(){
    this->countElements = 0;
}

bool Stack::isEmpty() {
    return this->countElements == 0;
}

void Stack::push(int element) {

    if(this->isFull())
        throw std::overflow_error("You can't stack more than 50 elements");

    this->elements[this->countElements] = element;
    this->countElements++;
}

int Stack::pop() {
    if(this->isEmpty())
        throw std::underflow_error("You can't pop a empty stack");

    this->countElements--;

    return this->elements[this->countElements];
}

int Stack::top() {

    if(this->isEmpty())
        throw std::underflow_error("You can't get the top element on a empty stack");

    return this->elements[this->countElements - 1];
}


bool Stack::isFull() {
    return this->countElements == Stack::MAX_SIZE;
}
