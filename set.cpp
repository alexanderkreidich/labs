#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<string> accounts;
    
    for (int i = 0; i < n; i++) {
        string account;
        int score;
        cin >> account >> score;

        // Если аккаунт ещё не добавлен в множество, засчитываем отправку
        if (accounts.find(account) == accounts.end()) {

            accounts.insert(account);
            cout << account << " засчитан. Результат: " << score << endl;
        } else {
            cout << account << " не засчитывается." << endl;
        }
    }
    
    return 0;
}
