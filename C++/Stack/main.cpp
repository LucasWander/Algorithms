#include <iostream>
#include <exception>
#include "Stack.hpp"

int main() {

    Stack *myStack = new Stack();

    try {
        myStack->pop();
    }
    catch(std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
