#include "queue.h"

Queue::Queue() : head(0), tail(0) {}

Queue::~Queue()
{
    while (!empty())
    {
        pop();
    }
}

void Queue::push(int value)
{
    Node *newNode = new Node(value);
    if (empty())
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void Queue::pop()
{
    if (!empty())
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        if (head == 0)
        {
            tail = 0;
        }
    }
}

int Queue::front() const
{
    if (!empty())
    {
        return head->data;
    }
    // Если очередь пустая, можно обработать ошибку по своему усмотрению
    return -1;
}

bool Queue::empty() const
{
    return head == 0;
}
