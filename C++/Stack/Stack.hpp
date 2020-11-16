class Stack {
public:
    static const int MAX_SIZE = 50;

    Stack();
    bool isEmpty();
    void push(int value);
    int pop();
    int top();
    bool isFull();
private:
    int countElements;
    int elements[Stack::MAX_SIZE];
};
