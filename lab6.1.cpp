#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool stackCheck(const string& exp ) {
    stack<char> s; // stack

    for (char ch : exp) {

        if (ch == '(' || ch == '{' || ch == '[') {

          s.push(ch);

        }
        
        else if (ch == ')' || ch == '}' || ch == ']') {

            if (s.empty()) {

              return false; //стек пуст но есть закрыв скобка

            }
        
            char top = s.top(); // вверхний стек

            if ((top == '(' && ch == ')') || (top == '[' && ch == ']') || (top == '{' && ch == '}')) {

              s.pop(); // пара скобок найдена

            }
            else {
              return false;
            }
        }
    }

    return s.empty(); // стек пуст

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

    string exp3 = "({)}";
    if (stackCheck(exp3) == true) {
      cout << exp3 + " -> " + " yes\n";
    }
    else {
      cout << exp3 + " -> " + " no\n";
    }

}