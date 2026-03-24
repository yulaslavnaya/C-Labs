#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

// Структура, описывающая автобус
struct Bus {
    int number;
    string driver;
    string route;
};

// Структура узла двусвязного списка
struct Node {
    Bus data;
    Node* next;
    Node* prev;
};

// Класс, управляющий автобусным парком
class BusPark {
private:
    Node* head;
    Node* tail;

public:
    // Конструктор: инициализирует пустой список
    BusPark() : head(nullptr), tail(nullptr) {}

    // Деструктор: освобождает всю выделенную память
    ~BusPark() {
        Node* p = head;
        while (p) {
            Node* temp = p;
            p = p->next;
            delete temp;
        }
    }

    // Метод добавления автобуса в парк (в конец списка)
    void addToPark(const Bus& bus) {
        Node* node = new Node{bus, nullptr, tail};

        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    // Метод отправки автобуса на маршрут (удаление из парка)
    void departBus(int number) {
        Node* p = head;
        while (p) {
            if (p->data.number == number) {
                if (p->prev) p->prev->next = p->next;
                else head = p->next;

                if (p->next) p->next->prev = p->prev;
                else tail = p->prev;

                cout << "Автобус " << number << " (водитель: " << p->data.driver << ") выехал на маршрут " << p->data.route << endl;                delete p;
                return;
            }
            p = p->next;
        }
        cout << "Автобус с номером " << number << " не найден в парке.\n";
    }

    // Метод возврата автобуса в парк (добавление)
    void returnBus(const Bus& bus) {
        addToPark(bus);
        cout << "Автобус " << bus.number << " (водитель: " << bus.driver << ") вернулся в парк.\n";
    }

    // Метод отображения всех автобусов в парке
    void showPark() const {
        if (!head) {
            cout << "Парк пуст.\n";
            return;
        }

        cout << "\n========== АВТОБУСЫ В ПАРКЕ ==========\n";
        Node* p = head;
        int count = 0;
        while (p) {
            count++;
            cout << "Номер: " << p->data.number
                    << " | Водитель: " << p->data.driver
                    << " | Маршрут: " << p->data.route << endl;
            p = p->next;
        }
        cout << "Всего автобусов: " << count << "\n";
    }
};

int main() {
    // Установка кодировки консоли для корректного отображения русского текста
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    BusPark park;

    park.addToPark({7, "Иванов И.И.", "Маршрут №7 (Центр-Север)"});
    park.addToPark({12, "Смирнов П.П.", "Маршрут №12 (Юг-Вокзал)"});
    park.addToPark({23, "Кузнецова А.Н.", "Маршрут №23 (Западный-Восток)"});

    park.showPark();

    cout << endl;
    park.departBus(12);
    park.showPark();

    cout << endl;
    park.returnBus({12, "Петров П.П.", "Маршрут №12 (Юг-Вокзал)"});
    park.showPark();

    return 0;
}
