#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

// Базовый класс Point (Точка)
class Point {
protected:
    int x, y;
    string color;

public:
    // Конструктор с параметрами по умолчанию
    Point(int x = 0, int y = 0, string color = "white") : x(x), y(y), color(color) {}

    // Виртуальный метод отображения объекта
    virtual void Show() const {
        cout << "Точка: x=" << x << ", y=" << y << ", color=" << color << endl;
    }

    // Виртуальный метод скрытия объекта
    virtual void Hide() const {
        cout << "Точка скрыта\n";
    }

    // Виртуальный метод перемещения объекта
    virtual void Move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    // Виртуальный деструктор
    virtual ~Point() {}
};

// Производный класс Krug (Круг)
class Krug : public Point {
protected:
    int radius;

public:
    // Конструктор круга
    Krug(int x = 0, int y = 0, int radius = 1, string color = "white")
        : Point(x, y, color), radius(radius) {}

    // Переопределение виртуального метода Show()
    void Show() const override {
        cout << "Круг: центр=(" << x << ", " << y << "), radius=" << radius
             << ", color=" << color << endl;
    }

    // Переопределение виртуального метода Hide()
    void Hide() const override {
        cout << "Круг скрыт\n";
    }
};

// Производный класс Ring (Кольцо)
class Ring : public Krug {
private:
    int width;

public:
    // Конструктор кольца
    Ring(int x = 0, int y = 0, int radius = 1, int width = 1, string color = "white")
        : Krug(x, y, radius, color), width(width) {}

    // Переопределение виртуального метода Show()
    void Show() const override {
        cout << "Кольцо: центр=(" << x << ", " << y << "), radius=" << radius
             << ", width=" << width << ", color=" << color << endl;
    }

    // Переопределение виртуального метода Hide()
    void Hide() const override {
        cout << "Кольцо скрыто\n";
    }
};

int main() {
    // Установка кодировки консоли для корректного отображения русского текста
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // Создание объектов различных классов
    Point p(10, 20, "red");
    Krug k(30, 40, 15, "green");
    Ring r(50, 60, 20, 5, "blue");

    // Демонстрация работы методов Show() для каждого объекта
    p.Show();
    k.Show();
    r.Show();

    cout << "\nПеремещение объектов:\n";
    // Перемещение объектов с помощью метода Move()
    p.Move(5, 5);
    k.Move(-10, 10);
    r.Move(0, -20);

    // Вывод новых координат после перемещения
    p.Show();
    k.Show();
    r.Show();

    return 0;
}
