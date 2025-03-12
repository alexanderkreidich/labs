#include <iostream>
#include <string>
#include "myStack.h"

using namespace std;

bool stackCheck(const string& exp) {
    myStack s; // стек

    for (int i = 0; i < exp.length(); ++i) {
        char ch = exp[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty()) {
                return false; // стек пуст, но есть закрывающая скобка
            }

            char top = s.top(); // верхний элемент стека

            if ((top == '(' && ch == ')') || 
                (top == '[' && ch == ']') || 
                (top == '{' && ch == '}')) {
                s.pop(); // найдена пара скобок
            }
            else {
                return false;
            }
        }
    }

    return s.isEmpty(); // если стек пуст, все скобки сопоставлены корректно
}



int main() {
    string exp1 = "2+4-5(87192479_7348){72648]76823[]";
    if (stackCheck(exp1) == true) {
      cout << exp1 + " -> " + " yes\n";
    }
    else {
      cout << exp1 + " -> " + " no\n";
    }

    string exp2 = "({})";
    if (stackCheck(exp2) == true) {
      cout << exp2 + " -> " + " yes\n";
    }
    else {
      cout << exp2 + " -> " + " no\n";
    }

    string exp3 = ")[]";
    if (stackCheck(exp3) == true) {
      cout << exp3 + " -> " + " yes\n";
    }
    else {
      cout << exp3 + " -> " + " no\n";
    }

    string exp4 = "({)}";
    if (stackCheck(exp4) == true) {
      cout << exp4 + " -> " + " yes\n";
    }
    else {
      cout << exp4 + " -> " + " no\n";
    }
}