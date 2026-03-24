#include <iostream>
#include <fstream>
#include <stdexcept>
#include <windows.h>
using namespace std;

// Пользовательский класс исключения для обработки файловых ошибок
class FileException : public exception {
private:
    string message;
public:
    // Конструктор класса
    FileException(const string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

// Класс для шифрования файлов
class FileEncryptor {
private:
    string inputFile;
    string outputFile;
    int key;

public:
    // Конструктор класса
    FileEncryptor(string in, string out, int k) : inputFile(in), outputFile(out), key(k) {}

    // Метод шифрования файла
    void encrypt() {
        ifstream fin(inputFile);
        if (!fin) throw FileException("Не удалось открыть входной файл.");

        ofstream fout(outputFile);
        if (!fout) throw FileException("Не удалось открыть выходной файл.");

        char ch;
        while (fin.get(ch)) {
            fout.put(ch + key);
        }

        fin.close();
        fout.close();
    }
};

int main() {
    // Установка кодировки консоли для корректного отображения русского текста
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    try {
        FileEncryptor enc("text.txt", "encrypted.txt", 2);
        enc.encrypt();
        cout << "Файл успешно зашифрован.\n";
    }
    catch (const FileException& e) {
        cout << "Ошибка файла: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "Общая ошибка: " << e.what() << endl;
    }

    return 0;
}
