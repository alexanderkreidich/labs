#include <iostream>
#include <cstring>

using namespace std;

// Пользовательская функция обмена, переименованная в mySwap
template<typename T>
void mySwap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

// =======================
// Задание 3: Быстрая сортировка для встроенных типов (шаблон)
// =======================
template<typename T>
int partition(T arr[], int low, int high) {
    T pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            mySwap(arr[i], arr[j]);
        }
    }
    mySwap(arr[i+1], arr[high]);
    return i+1;
}

template<typename T>
void quickSort(T arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// =======================
// Задание 4: Быстрая сортировка для пар <Фамилия, возраст>
// =======================
struct Pair {
    char surname[50];
    int age;
};

int comparePair(const Pair &a, const Pair &b) {
    return strcmp(a.surname, b.surname);
}

int partitionPair(Pair arr[], int low, int high) {
    Pair pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (comparePair(arr[j], pivot) < 0) {
            i++;
            mySwap(arr[i], arr[j]);
        }
    }
    mySwap(arr[i+1], arr[high]);
    return i+1;
}

void quickSortPair(Pair arr[], int low, int high) {
    if (low < high) {
        int pi = partitionPair(arr, low, high);
        quickSortPair(arr, low, pi - 1);
        quickSortPair(arr, pi + 1, high);
    }
}

// =======================
// Задание 5: Быстрая сортировка для структуры <Surname, Name, Age>
// =======================
struct Person {
    char surname[50];
    char name[50];
    int age;
};

int comparePerson(const Person &a, const Person &b) {
    int cmp = strcmp(a.surname, b.surname);
    if (cmp == 0) {
        cmp = strcmp(a.name, b.name);
        if (cmp == 0) {
            if (a.age < b.age)
                return -1;
            else if (a.age > b.age)
                return 1;
            else
                return 0;
        }
    }
    return cmp;
}

int partitionPerson(Person arr[], int low, int high) {
    Person pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (comparePerson(arr[j], pivot) < 0) {
            i++;
            mySwap(arr[i], arr[j]);
        }
    }
    mySwap(arr[i+1], arr[high]);
    return i+1;
}

void quickSortPerson(Person arr[], int low, int high) {
    if (low < high) {
        int pi = partitionPerson(arr, low, high);
        quickSortPerson(arr, low, pi - 1);
        quickSortPerson(arr, pi + 1, high);
    }
}

// =======================
// Функция main с демонстрацией работы
// =======================
int main() {
    // Демонстрация для встроенных типов: int
    int arrInt[] = {10, 7, 8, 9, 1, 5};
    int nInt = sizeof(arrInt)/sizeof(arrInt[0]);
    cout << "Исходный массив int: ";
    for (int i = 0; i < nInt; i++)
        cout << arrInt[i] << " ";
    cout << endl;
    
    quickSort(arrInt, 0, nInt - 1);
    
    cout << "Отсортированный массив int: ";
    for (int i = 0; i < nInt; i++)
        cout << arrInt[i] << " ";
    cout << "\n\n";
    
    // Демонстрация для встроенных типов: double
    double arrDouble[] = {3.14, 2.71, 1.41, 1.73, 0.577};
    int nDouble = sizeof(arrDouble)/sizeof(arrDouble[0]);
    cout << "Исходный массив double: ";
    for (int i = 0; i < nDouble; i++)
        cout << arrDouble[i] << " ";
    cout << endl;
    
    quickSort(arrDouble, 0, nDouble - 1);
    
    cout << "Отсортированный массив double: ";
    for (int i = 0; i < nDouble; i++)
        cout << arrDouble[i] << " ";
    cout << "\n\n";
    
    // Демонстрация сортировки для пар <Фамилия, возраст>
    Pair arrPair[] = { {"Smith", 30}, {"Anderson", 25}, {"Brown", 40}, {"Davis", 20} };
    int nPair = sizeof(arrPair)/sizeof(arrPair[0]);
    cout << "Исходный массив Pair:" << endl;
    for (int i = 0; i < nPair; i++) {
        cout << arrPair[i].surname << " " << arrPair[i].age << endl;
    }
    cout << endl;
    
    quickSortPair(arrPair, 0, nPair - 1);
    
    cout << "Отсортированный массив Pair (по фамилии):" << endl;
    for (int i = 0; i < nPair; i++) {
        cout << arrPair[i].surname << " " << arrPair[i].age << endl;
    }
    cout << "\n";
    
    // Демонстрация сортировки для структуры <Surname, Name, Age>
    Person arrPerson[] = {
        {"Smith", "John", 30},
        {"Anderson", "Alice", 25},
        {"Brown", "Charlie", 40},
        {"Davis", "Bob", 20},
        {"Brown", "Adam", 35}
    };
    int nPerson = sizeof(arrPerson)/sizeof(arrPerson[0]);
    cout << "Исходный массив Person:" << endl;
    for (int i = 0; i < nPerson; i++) {
        cout << arrPerson[i].surname << " " << arrPerson[i].name << " " << arrPerson[i].age << endl;
    }
    cout << endl;
    
    quickSortPerson(arrPerson, 0, nPerson - 1);
    
    cout << "Отсортированный массив Person (по фамилии, имени, возрасту):" << endl;
    for (int i = 0; i < nPerson; i++) {
        cout << arrPerson[i].surname << " " << arrPerson[i].name << " " << arrPerson[i].age << endl;
    }
    
    return 0;
}
