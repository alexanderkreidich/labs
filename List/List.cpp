#include "List.h"

template <typename T>
List<T>::List() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
List<T>::~List() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
void List<T>::push_back(const T& value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    ++size;
}

template <typename T>
void List<T>::push_front(const T& value) {
    Node* newNode = new Node(value, head);
    head = newNode;
    if (!tail) {
        tail = newNode;
    }
    ++size;
}

template <typename T>
size_t List<T>::getSize() const {
    return size;
}
