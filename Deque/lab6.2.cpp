#include <iostream>
#include <string>
#include "Deque.h"

using namespace std;

int main()
{
    string input;
    cout << "Введите строку: ";
    getline(cin, input);

    Deque deque;
    // Считываем строку посимвольно и добавляем каждый символ в конец дека
    for (size_t i = 0; i < input.size(); i++)
    {
        deque.push_back(input[i]);
    }

    bool isPalindrome = true;
    // Пока в деке более одного элемента, сравниваем первый и последний символ
    while (deque.size() > 1)
    {
        char first = deque.front();
        char last = deque.back();
        if (first != last)
        {
            isPalindrome = false;
            break;
        }
        // Удаляем сравнившиеся элементы с обоих концов
        deque.pop_front();
        deque.pop_back();
    }

    if (isPalindrome)
    {
        cout << "Строка является палиндромом." << endl;
    }
    else
    {
        cout << "Строка не является палиндромом." << endl;
    }

    return 0;
}
