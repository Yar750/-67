#include <iostream>
#include <string>
using namespace std;

class Vegetable {
protected:
    string name;
    double weight;
    static int count;

public:
    Vegetable(string n, double w) : name(n), weight(w) {
        count++;
    }

    virtual ~Vegetable() {}

    virtual void showInfo() const = 0;
    virtual string getType() const = 0;

    double getWeight() const { return weight; }

    static int getCount() { return count; }
};

int Vegetable::count = 0;

class Carrot : public Vegetable {
private:
    double length;

public:
    Carrot(string n, double w, double l) : Vegetable(n, w), length(l) {}

    void showInfo() const override {
        cout << "Морковь: " << name << ", вес: " << weight
            << " г, длина: " << length << " см" << endl;
    }

    string getType() const override {
        return "Корнеплод (морковь)";
    }
};

class Potato : public Vegetable {
private:
    string variety;

public:
    Potato(string n, double w, string v) : Vegetable(n, w), variety(v) {}

    void showInfo() const override {
        cout << "Картофель: " << name << ", вес: " << weight
            << " г, сорт: " << variety << endl;
    }

    string getType() const override {
        return "Клубнеплод (картофель)";
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Carrot carrot("Морковь мытая", 150, 18.5);
    Potato potato("Картофель молодой", 200, "Белорусский");

    cout << "Раннее связывание" << endl;
    carrot.showInfo();
    cout << "Тип: " << carrot.getType() << endl;
    cout << "Вес: " << carrot.getWeight() << " г" << endl;

    potato.showInfo();
    cout << "Тип: " << potato.getType() << endl;
    cout << "Вес: " << potato.getWeight() << " г" << endl;

    cout << "\nПозднее связывание" << endl;
    cout << "Выберите овощ (1 - морковь, 2 - картофель): ";
    int choice;
    cin >> choice;

    Vegetable* obj = nullptr;
    if (choice == 1)
        obj = new Carrot("Морковь с грядки", 120, 20.0);
    else if (choice == 2)
        obj = new Potato("Картофель с рынка", 180, "Скарб");
    else {
        cout << "Неверный выбор! Завершение программы." << endl;
        return 1;
    }

    obj->showInfo();
    cout << "Тип: " << obj->getType() << endl;
    cout << "Вес: " << obj->getWeight() << " г" << endl;

    delete obj;

    cout << "\nВсего создано овощей: " << Vegetable::getCount() << endl;

    return 0;
}
