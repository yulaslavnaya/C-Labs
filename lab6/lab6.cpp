#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;

class Stroka {
private:
    char str[80];

public:
    // Конструктор по умолчанию с параметром по умолчанию
    Stroka(const char* s = "") {
        strcpy(str, s);
    }

    // Конструктор копирования
    Stroka(const Stroka& s) {
        strcpy(str, s.str);
    }

    // Перегрузка оператора присваивания
    Stroka& operator=(const Stroka& s) {
        if (this != &s) {
            strcpy(str, s.str);
        }
        return *this;
    }

    // Перегрузка оператора сложения (конкатенации строк)
    Stroka operator+(const Stroka& s) const {
        Stroka temp(*this);
        strcat(temp.str, s.str);
        return temp;
    }

    // Перегрузка оператора сравнения ==
    int operator==(const Stroka& s) const {
        return strcmp(str, s.str) == 0;
    }

    // Метод для получения длины строки
    int dlina() const {
        return strlen(str);
    }

    // Метод для ввода строки с клавиатуры
    void vvod() {
        cin.getline(str, 80);
    }
    
    // Метод для вывода строки на экран
    void vyvod() const {
        cout << str;
    }
};

int main() {
    // Установка кодировки консоли для корректного отображения русского текста~
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // Создание объектов класса Stroka различными способами
    Stroka s1("qwert");
    Stroka s3;
    Stroka s4(s1);
    Stroka s5;

    cout << "Введите строку: ";
    s3.vvod();

    cout << "Введенная строка: ";
    s3.vyvod();
    cout << endl;

    s5 = s4 + s3;
    cout << "Результат сложения строк: ";
    s5.vyvod();
    cout << endl;

    cout << "Длина s5 = " << s5.dlina() << endl;

    if (s3 == s4)
        cout << "Строки s3 и s4 равны\n";
    else
        cout << "Строки s3 и s4 не равны\n";

    return 0;
}
