#ifndef DEQUE_H
#define DEQUE_H

class Deque {
private:
    struct Node {
        char data;
        Node* next;
        Node* prev;
        Node(char d) : data(d), next(0), prev(0) {}
    };
    Node* head;
    Node* tail;
    int count; // количество элементов в деке
public:
    Deque();
    ~Deque();

    // Добавление элемента в конец дека
    void push_back(char c);

    // Добавление элемента в начало дека
    void push_front(char c);

    // Удаление элемента с конца дека
    void pop_back();

    // Удаление элемента с начала дека
    void pop_front();

    // Возврат первого элемента дека
    char front() const;

    // Возврат последнего элемента дека
    char back() const;

    // Проверка, пустой ли дек
    bool isEmpty() const;

    // Возвращает количество элементов
    int size() const;
};

#endif // DEQUE_H
