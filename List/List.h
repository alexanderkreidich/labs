#ifndef LIST_H
#define LIST_H

#include <cstddef> // Для size_t

// Обобщённый класс односвязного списка
template <typename T>
class List {
private:
    // Вложенная структура узла списка
    struct Node {
        T data;
        Node* next;
        Node(const T& value, Node* nextNode = nullptr)
            : data(value), next(nextNode) {}
    };

    Node* head;   // указатель на первый элемент
    Node* tail;   // указатель на последний элемент
    size_t size;  // количество элементов в списке

public:
    List();
    ~List();

    // Добавление элемента в конец списка
    void push_back(const T& value);
    // Добавление элемента в начало списка
    void push_front(const T& value);
    // Получение количества элементов в списке
    size_t getSize() const;

    // Итератор для обхода списка
    class Iterator {
    private:
        Node* current;
    public:
        Iterator(Node* node) : current(node) {}
        T& operator*() { return current->data; }
        Iterator& operator++() { 
            if (current) current = current->next;
            return *this;
        }
        bool operator!=(const Iterator& other) const { return current != other.current; }
    };

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }
};

// Для шаблонного класса реализация должна быть доступна при компиляции,
// поэтому включаем файл с реализациями.
#include "List.cpp"

#endif // LIST_H
