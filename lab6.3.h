// Stack.h - Header file for Stack ADT using SLL
#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

class Stack {
private:
    Node* top;
public:
    Stack() { top = nullptr; }
    ~Stack();
    void push(char data);
    char pop();
    char peek();
    bool isEmpty();
};

Stack::~Stack() {
    while (!isEmpty()) pop();
}

void Stack::push(char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

char Stack::pop() {
    if (isEmpty()) return '\0';
    char temp = top->data;
    Node* delNode = top;
    top = top->next;
    delete delNode;
    return temp;
}

char Stack::peek() {
    return (isEmpty()) ? '\0' : top->data;
}

bool Stack::isEmpty() {
    return top == nullptr;
}

#endif // STACK_H