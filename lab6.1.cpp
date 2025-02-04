#include <iostream>
#include <stack>
#include <string>

using namespace ltd;

bool stackCheck(const string& exp ) {
    stack<char> s; // stack

    for (ch : exp) {

        if (ch == "(" || ch == "{" || ch == "[") {

            s.push(ch);

        }
        
        else if (ch == ")" || ch == "}" || ch == "]") {

            if (s.empty()) {

                return false; //стек пуст но есть закрыв скобка

            }
        
            char top = s.top(); // вверхний стек

            if ((top + ch == "()") || (top + ch == "[]") || (top + ch == "{}")) {

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
    cout << exp1 + " -> " + stackCheck(exp1);
    string exp2 = "({})";
    cout << exp2 + " -> " + stackCheck(exp2);
    string exp3 = "({)}";
    cout << exp3 + " -> " + stackCheck(exp3);

}