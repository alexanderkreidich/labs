#ifndef QUEUE_H
#define QUEUE_H

struct Node
{
    int data;
    Node *next;
    Node(int value) : data(value), next(0) {}
};

class Queue
{
private:
    Node *head; // указатель на начало очереди
    Node *tail; // указатель на конец очереди
public:
    Queue();
    ~Queue();

    void push(int value); // добавление элемента в конец очереди
    void pop();           // удаление элемента из начала очереди
    int front() const;    // получение элемента в начале очереди
    bool empty() const;   // проверка на пустоту очереди
};

#endif // QUEUE_H
