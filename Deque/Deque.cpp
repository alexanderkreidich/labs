#include "Deque.h"

Deque::Deque() : head(0), tail(0), count(0) {}

Deque::~Deque()
{
    while (!isEmpty())
    {
        pop_front();
    }
}

void Deque::push_back(char c)
{
    Node *newNode = new Node(c);
    if (isEmpty())
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    count++;
}

void Deque::push_front(char c)
{
    Node *newNode = new Node(c);
    if (isEmpty())
    {
        head = tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    count++;
}

void Deque::pop_back()
{
    if (isEmpty())
    {
        return;
    }
    Node *temp = tail;
    if (head == tail)
    { // только один элемент
        head = tail = 0;
    }
    else
    {
        tail = tail->prev;
        tail->next = 0;
    }
    delete temp;
    count--;
}

void Deque::pop_front()
{
    if (isEmpty())
    {
        return;
    }
    Node *temp = head;
    if (head == tail)
    { // только один элемент
        head = tail = 0;
    }
    else
    {
        head = head->next;
        head->prev = 0;
    }
    delete temp;
    count--;
}

char Deque::front() const
{
    if (isEmpty())
    {
        return '\0';
    }
    return head->data;
}

char Deque::back() const
{
    if (isEmpty())
    {
        return '\0';
    }
    return tail->data;
}

bool Deque::isEmpty() const
{
    return head == 0;
}

int Deque::size() const
{
    return count;
}
