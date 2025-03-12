#include "Node.h"

class myStack {
public:
    myStack();
    
    ~myStack();

    // Помещает символ c в стек
    void push(char c);

    // Возвращает верхний элемент стека без удаления.
    char top() const;

    // Извлекает верхний элемент из стека и возвращает его.
    char pop();

    // Проверяет, пуст ли стек.
    bool isEmpty() const;

private:
    Node* topPtr; // Указатель на вершину стека (последний добавленный узел)
};
