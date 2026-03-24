#include <iostream>
#include <windows.h>
using namespace std;

// 1. Возведение 2 в степень
void power2() {
    int k;
    cout << "Введите k: ";
    cin >> k;

    int p = 1;
    for (int i = 0; i < k; i++) {
        p *= 2;
        cout << "2^" << i + 1 << " = " << p << endl;
    }
}

// 2. Операции с указателями
void pointerDemo() {
    int mas[3] = {100, 200, 300};
    int *ptr1, *ptr2;

    ptr1 = mas;
    ptr2 = &mas[2];

    cout << "\nРабота с указателями:\n";
    cout << "*ptr1 = " << *ptr1 << endl;
    cout << "ptr1[1] = " << ptr1[1] << endl;
    cout << "*(ptr1 + 2) = " << *(ptr1 + 2) << endl;
    cout << "*ptr2 = " << *ptr2 << endl;
    cout << "ptr2 - ptr1 = " << ptr2 - ptr1 << endl;
}

// Перегруженная функция для вычисления объема куба
double volume(double a) {
    return a * a * a;
}

// Перегруженная функция для вычисления объема прямоугольного параллелепипеда
double volume(double a, double b, double c) {
    return a * b * c;
}

// Перегруженная функция для обмена значениями двух целых чисел
void swapValues(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

// Перегруженная функция для обмена значениями двух чисел с плавающей точкой
void swapValues(double &a, double &b) {
    double t = a;
    a = b;
    b = t;
}

int main() {
    // Установка кодировки консоли для корректного отображения русского текста
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    power2();
    pointerDemo();

    double side, x, y, z;
    cout << "\nВведите сторону куба: ";
    cin >> side;
    cout << "Объем куба = " << volume(side) << endl;

    cout << "Введите длину, ширину и высоту параллелепипеда: ";
    cin >> x >> y >> z;
    cout << "Объем параллелепипеда = " << volume(x, y, z) << endl;

    int i1 = 10, i2 = 20;
    double d1 = 1.5, d2 = 2.5;

    cout << "\nДо обмена int: " << i1 << " " << i2 << endl;
    swapValues(i1, i2);
    cout << "После обмена int: " << i1 << " " << i2 << endl;

    cout << "До обмена double: " << d1 << " " << d2 << endl;
    swapValues(d1, d2);
    cout << "После обмена double: " << d1 << " " << d2 << endl;

    return 0;
}
