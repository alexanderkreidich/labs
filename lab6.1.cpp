#include <iostream>
#include <string>

using namespace std;

struct Node {
    char data;    // Значение, которое помещаем в стек (символ).
    Node* next;   // Указатель на следующий узел.
};

class myStack {
public:
    myStack() : topPtr(nullptr) {}
    
    ~myStack() {
        while (topPtr != nullptr) {
            Node* temp = topPtr;
            topPtr = topPtr->next;
            delete temp;
        }
    }
    
    void push(char c) {
        Node* newNode = new Node;
        newNode->data = c;
        newNode->next = topPtr;
        topPtr = newNode;
    }
    
    char pop() {
        if (isEmpty()) return '\0'; // Если стек пуст, возвращаем специальное значение.
        char c = topPtr->data;
        Node* temp = topPtr;
        topPtr = topPtr->next;
        delete temp;
        return c;
    }
    
    // Метод для получения верхнего элемента стека без удаления
    char top() const {
        if (isEmpty()) return '\0'; // Можно выбросить исключение или вернуть специальное значение
        return topPtr->data;
    }
    
    bool isEmpty() const {
        return topPtr == nullptr;
    }
    
private:
    Node* topPtr; // Указатель на вершину стека.
};

bool stackCheck(const string& exp) {
    myStack s; // Создаем экземпляр стека

    for (char ch : exp) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty()) {
                return false; // Стек пуст, но встретилась закрывающая скобка
            }
            
            char topChar = s.top(); // Получаем верхний элемент стека
            if ((topChar == '(' && ch == ')') ||
                (topChar == '[' && ch == ']') ||
                (topChar == '{' && ch == '}')) {
                s.pop(); // Пара скобок найдена, удаляем верхний элемент
            } else {
                return false; // Несоответствие скобок
            }
        }
    }

    return s.isEmpty(); // Если стек пуст, значит все скобки корректно закрыты
}

int main() {
    string exp1 = "2+4-5(87192479_7348){72648]76823[]";
    cout << exp1 << " -> " << (stackCheck(exp1) ? "yes" : "no") << "\n";

    string exp2 = "({})";
    cout << exp2 << " -> " << (stackCheck(exp2) ? "yes" : "no") << "\n";

    string exp3 = "({)}";
    cout << exp3 << " -> " << (stackCheck(exp3) ? "yes" : "no") << "\n";

    return 0;
}
