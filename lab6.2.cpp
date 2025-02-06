#include <iostream>
#include <deque>

using namespace std;

bool checkPalindrome ( string& pali) {

  deque<char> d(pali.begin(), pali.end());

      // Пока в деке больше одного элемента, сравниваем первый и последний символ.
    while (d.size() > 1) {
        if (d.front() != d.back()) {
            // Если символы не совпадают, значит строка не палиндром.
            return false;
        }
        // Если совпадают, удаляем их из дека.
        d.pop_front();
        d.pop_back();
    }

    return true; // строка палиндром


}

int main() {
    string input = "MADAM";
    cout << "Введите строку: MADAM ";

    if (checkPalindrome(input))
        cout << "Строка является палиндромом." << endl;
    else
        cout << "Строка не является палиндромом." << endl;

    return 0;
}
