#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <windows.h>
using namespace std;

// Функция просмотра содержимого файла
void viewFile(const string& filename) {
    ifstream fin(filename);
    if (!fin) {
        cout << "Файл не открыт.\n";
        return;
    }

    char ch;
    while (fin.get(ch)) cout << ch;
    cout << endl;
    fin.close();
}

// Функция добавления строки в файл, если строка не содержит пробелов
void appendIfNoSpaces(const string& filename, const string& text) {
    bool hasSpace = false;
    for (char c : text) {
        if (c == ' ') {
            hasSpace = true;
            break;
        }
    }

    if (hasSpace) {
        cout << "Строка содержит пробелы, запись не выполнена.\n";
        return;
    }

    ofstream fout(filename, ios::app);
    fout << text << endl;
    fout.close();
    cout << "Строка добавлена.\n";
}

// Функция подсчета букв, цифр и знаков препинания в файле
void countLettersDigitsPunct(const string& filename) {
    ifstream fin(filename);
    if (!fin) {
        cout << "Файл не открыт.\n";
        return;
    }

    int letters = 0, digits = 0, punct = 0;
    char ch;
    while (fin.get(ch)) {
        if (isalpha((unsigned char)ch)) letters++;
        else if (isdigit((unsigned char)ch)) digits++;
        else if (ispunct((unsigned char)ch)) punct++;
    }

    cout << "Букв: " << letters << endl;
    cout << "Цифр: " << digits << endl;
    cout << "Знаков препинания: " << punct << endl;

    fin.close();
}

// Функция разбиения файла на страницы (пагинация)
void paginateFile(const string& input, const string& output, int linesPerPage = 34) {
    ifstream fin(input);
    ofstream fout(output);

    if (!fin || !fout) {
        cout << "Ошибка открытия файлов.\n";
        return;
    }

    string line;
    int lineCount = 0;
    int page = 1;

    fout << "Страница " << page << "\n";
    while (getline(fin, line)) {
        fout << line << "\n";
        lineCount++;

        if (lineCount == linesPerPage) {
            page++;
            fout << "\f\n";
            fout << "Страница " << page << "\n";
            lineCount = 0;
        }
    }

    fin.close();
    fout.close();
    cout << "Пагинация завершена.\n";
}

// Функция шифрования файла с помощью сдвига символов (шифр Цезаря)
void encryptFile(const string& input, const string& output, int key) {
    ifstream fin(input);
    ofstream fout(output);

    if (!fin || !fout) {
        cout << "Ошибка открытия файлов.\n";
        return;
    }

    char ch;
    while (fin.get(ch)) {
        fout.put(ch + key);
    }

    fin.close();
    fout.close();
    cout << "Файл зашифрован.\n";
}

// Функция подсчета количества символов и слов в файле
void countWordsAndChars(const string& filename) {
    ifstream fin(filename);
    if (!fin) {
        cout << "Файл не открыт.\n";
        return;
    }

    int chars = 0, words = 0;
    string word;
    char ch;

    while (fin.get(ch)) chars++;
    fin.clear();
    fin.seekg(0);

    while (fin >> word) words++;

    cout << "Символов: " << chars << endl;
    cout << "Слов: " << words << endl;

    fin.close();
}

int main() {
    // Установка кодировки консоли для корректного отображения русского текста
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    string filename = "text.txt";

    cout << "1. Просмотр файла:\n";
    viewFile(filename);

    cout << "\n2. Добавление строки без пробелов:\n";
    appendIfNoSpaces(filename, "СтрокаБезПробелов");

    cout << "\n3. Подсчет букв, цифр и знаков препинания:\n";
    countLettersDigitsPunct(filename);

    cout << "\n4. Разбиение на страницы:\n";
    paginateFile(filename, "pages.txt");

    cout << "\n5. Шифрование файла:\n";
    encryptFile(filename, "encrypted.txt", 3);

    cout << "\n6. Подсчет слов и символов:\n";
    countWordsAndChars(filename);

    return 0;
}
