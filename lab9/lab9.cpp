#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;

// Шаблонная функция сортировки массива (пузырьковая сортировка)
template <class T>
void Sort(T array[], size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                T tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

// Перегруженная шаблонная функция для поиска максимума из двух значений
template <class T>
T getmax(T t1, T t2) {
    return (t1 > t2) ? t1 : t2;
}

// Перегруженная шаблонная функция для поиска максимума в массиве
template <class T>
T getmax(T t[], size_t size) {
    T result = t[0];
    for (size_t i = 1; i < size; i++)
        if (t[i] > result) result = t[i];
    return result;
}

// Специализация шаблона для работы с C-строками (char*)
char* getmax(char* s1, char* s2) {
    return (strcmp(s1, s2) > 0) ? s1 : s2;
}

// Шаблонный класс стека с фиксированным размером
template <class T, int maxSize>
class TStack {
private:
    T items[maxSize];
    int topIndex;

public:
    // Конструктор: инициализирует стек пустым состоянием
    TStack() : topIndex(-1) {}

    // Метод добавления элемента в стек
    bool push(T item) {
        if (topIndex >= maxSize - 1) return false;
        items[++topIndex] = item;
        return true;
    }

    // Метод извлечения элемента из стека
    bool pop(T& item) {
        if (topIndex < 0) return false;
        item = items[topIndex--];
        return true;
    }

    // Метод проверки пустоты стека
    bool empty() const {
        return topIndex == -1;
    }
};

int main() {
    // Установка кодировки консоли для корректного отображения русского текста
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // Демонстрация работы шаблонной функции Sort с массивом int
    int a[] = {100, 200, 300, 10, 250, 30, 0};
    int n = sizeof(a) / sizeof(a[0]);

    Sort(a, n);
    cout << "Отсортированный массив:\n";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    // Демонстрация работы getmax с двумя значениями
    int x = 3, y = 5;
    cout << "max(" << x << ", " << y << ") = " << getmax(x, y) << endl;

    // Демонстрация работы getmax с массивом
    cout << "max массива = " << getmax(a, n) << endl;

    // Демонстрация работы специализации getmax для C-строк
    char s1[] = "строка1";
    char s2[] = "строка2";
    cout << "max строк = " << getmax(s1, s2) << endl;

    // Демонстрация работы шаблонного класса TStack
    TStack<int, 10> st;
    // Добавляем элементы в стек
    st.push(5);
    st.push(15);
    st.push(25);
    // Извлекаем и выводим все элементы из стека
    cout << "Стек:\n";
    int val;
    while (st.pop(val)) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
