#include "myStack.h"

myStack::myStack() : topPtr(0) {}
    
myStack::~myStack() {
    // Освобождаем память, выделенную под узлы стека
    while (topPtr != 0) {
        Node* temp = topPtr;
        topPtr = topPtr->next;
        delete temp;
    }
}

void myStack::push(char c) {
    // Создаем новый узел и добавляем его на вершину стека
    Node* newNode = new Node;
    newNode->data = c;
    newNode->next = topPtr;
    topPtr = newNode;
}

char myStack::top() const {
    // Если стек пуст, возвращаем специальное значение
    if (isEmpty())
        return '\0';
    return topPtr->data;
}

char myStack::pop() {
    // Если стек пуст, возвращаем специальное значение
    if (isEmpty())
        return '\0';
    char c = topPtr->data;
    Node* temp = topPtr;
    topPtr = topPtr->next;
    delete temp;
    return c;
}

bool myStack::isEmpty() const {
    return topPtr == 0;
}
