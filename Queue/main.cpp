#include <iostream>
#include "queue.h"

using namespace std;

int main(){
    int n;
    cout << "Введите количество чисел n: ";
    cin >> n;
        
    int numb = 1;
    cout << numb << " ";
    
    Queue q2, q3, q5;
    
    // Начальные значения: 1*2, 1*3, 1*5
    q2.push(numb * 2);
    q3.push(numb * 3);
    q5.push(numb * 5);
    
    // Генерируем оставшиеся числа
    for(int i = 2; i <= n; i++){
        // Выбираем минимальное значение из первых элементов очередей
        int next2 = q2.front();
        int next3 = q3.front();
        int next5 = q5.front();
        
        numb = min(next2, min(next3, next5));
        cout << numb << " ";
        
        // Избавляемся от повторов: если очереди дают одинаковые значения – извлекаем их
        if(numb == next2) q2.pop();
        if(numb == next3) q3.pop();
        if(numb == next5) q5.pop();
        
        // Добавляем в очереди новые кратные
        q2.push(numb * 2);
        q3.push(numb * 3);
        q5.push(numb * 5);
    }
    
    cout << endl;
    return 0;
}
