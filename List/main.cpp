#include <iostream>
#include <map>
#include <string>
#include "List.h"

using namespace std;

int main() {
    int grp;
    string surname;

    // Список для хранения порядка появления групп (без использования vector)
    List<int> groupOrder;
    // Отображение: номер группы -> список фамилий студентов (с использованием нашего List)
    map<int, List<string>> groupStudents;

    // Чтение входных данных: <номер группы> <Фамилия>
    // Читаем данные напрямую из cin
    while (cin >> grp >> surname) {
        // Если группа встречается впервые, запоминаем порядок её появления
        if (groupStudents.find(grp) == groupStudents.end()) {
            groupOrder.push_back(grp);
            groupStudents[grp] = List<string>();
        }
        // Добавляем фамилию студента в список соответствующей группы
        groupStudents[grp].push_back(surname);
    }

    // Вывод студентов по группам с сохранением порядка появления групп
    for (auto it = groupOrder.begin(); it != groupOrder.end(); ++it) {
        int groupNum = *it;
        cout << groupNum << endl;
        for (auto sit = groupStudents[groupNum].begin(); sit != groupStudents[groupNum].end(); ++sit) {
            cout << *sit << endl;
        }
    }

    return 0;
}
