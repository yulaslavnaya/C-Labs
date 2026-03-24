#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;

int main() {
    // Установка кодировки консоли для корректного отображения русского текста
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    char str1[80] = "qwerty";
    char str2[] = "1234567890";

    cout << "str1 = " << str1 << endl;
    cout << "str2 = " << str2 << endl;

    cout << "\nДлина str1 = " << strlen(str1) << endl;
    cout << "Длина str2 = " << strlen(str2) << endl;

    cout << "\nСравнение строк strcmp(str1, str2) = " << strcmp(str1, str2) << endl;

    // Копирование строки с помощью strcpy()
    char copy1[100];
    strcpy(copy1, str1);
    cout << "\nРезультат копирования str1: " << copy1 << endl;

    // Конкатенация строк с помощью strcat()
    strcat(str1, str2);
    cout << "Результат сцепления str1 + str2: " << str1 << endl;

    // Динамическое выделение памяти под строки
    char* d1 = new char[100];
    char* d2 = new char[100];

    // Копируем строки в динамически выделенную память
    strcpy(d1, "динамическая_строка_1");
    strcpy(d2, "динамическая_строка_2");

    cout << "\nДинамические строки:\n";
    cout << "d1 = " << d1 << endl;
    cout << "d2 = " << d2 << endl;

    cout << "strlen(d1) = " << strlen(d1) << endl;
    cout << "strcmp(d1, d2) = " << strcmp(d1, d2) << endl;

    // Конкатенация динамических строк с помощью strcat()
    strcat(d1, d2);
    cout << "Результат сцепления strcat(d1, d2): " << d1 << endl;

    // Освобождение динамически выделенной памяти
    delete[] d1;
    delete[] d2;

    return 0;
}
