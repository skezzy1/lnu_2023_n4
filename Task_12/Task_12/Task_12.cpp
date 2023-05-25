#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;
class Subscriber {
public:
    Subscriber(const string& name, const string& address, double debt)
        : name(name), address(address), debt(debt) {}

    string getName() const {
        return name;
    }

    string getAddress() const {
        return address;
    }

    double getDebt() const {
        return debt;
    }

    void setDebt(double newDebt) {
        debt = newDebt;
    }

    void printFullInfo() const {
       cout << "Ім'я: " << name << ", Адреса: " << address << ", Заборгованість: " << debt << " грн" << endl;
    }

private:
    string name;
    string address;
    double debt;
};

class TelephoneStation {
public:
    void addSubscriber(const Subscriber& subscriber) {
        subscribers.push_back(subscriber);
    }

    void removeSubscriber(const string& name) {
        for (auto it = subscribers.begin(); it != subscribers.end(); ++it) {
            if (it->getName() == name) {
                subscribers.erase(it);
                cout << "Абонента " << name << " вилучено зі списку абонентів." << endl;
                return;
            }
        }
        cout << "Абонента з ім'ям " << name << " не знайдено." << endl;
    }

    void printSubscribersShortInfo() const {
        cout << "Список абонентів (скорочена інформація):" << endl;
        for (const auto& subscriber : subscribers) {
            cout << "Ім'я: " << subscriber.getName() << ", Адреса: " << subscriber.getAddress() << endl;
        }
    }

    void printSubscribersFullInfo() const {
        cout << "Список абонентів (повна інформація):" << endl;
        for (const auto& subscriber : subscribers) {
            subscriber.printFullInfo();
        }
    }

    void calculateAndAnalyzeDebts() const {
        double totalDebt = 0.0;
        int numDebtors = 0;

        for (const auto& subscriber : subscribers) {
            totalDebt += subscriber.getDebt();
            if (subscriber.getDebt() > 0) {
                numDebtors++;
            }
        }

        cout << "Загальна заборгованість: " << totalDebt << " грн" << endl;
        cout << "Кількість боржників: " << numDebtors << endl;

        cout << "Повна інформація про боржників:" << endl;
        for (const auto& subscriber : subscribers) {
            if (subscriber.getDebt() > 0) {
                subscriber.printFullInfo();
            }
        }
    }
    void searchSubscriberByAddress(const string& address) const {
        cout << "Результати пошуку абонента за адресою " << address << ":" << endl;
        bool found = false; for (const auto& subscriber : subscribers) { 
            if (subscriber.getAddress() == address) 
            {
                subscriber.printFullInfo(); found = true;
            } 
        }
        if (!found) {
            cout << "Абонента за вказаною адресою не знайдено." << endl;
        }
    }
    void searchDebtors() const {
        cout << "Список абонентів з заборгованістю:" << endl;
        bool found = false;
        for (const auto& subscriber : subscribers) {
            if (subscriber.getDebt() > 0) {
                subscriber.printFullInfo();
                found = true;
            }
        }

        if (!found) {
            cout << "Немає абонентів з заборгованістю." << std::endl;
        }
    }
private:
    std::vector<Subscriber> subscribers;
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string SubscribersFile("file.txt");
    Subscriber subscriber1("Петренко", "вул. Шевченка 1", 150.0);
    Subscriber subscriber2("Петров", "вул. Дудаєва 10", 0.0);
    Subscriber subscriber3("Сидоров", "вул. Наукова", 9.0);
    TelephoneStation telephoneStation;
    // Додаємо абонентів до телефонної станції
    telephoneStation.addSubscriber(subscriber1);
    telephoneStation.addSubscriber(subscriber2);
    telephoneStation.addSubscriber(subscriber3);
    cout << endl;
    // Виводимо скорочену інформацію про абонентів
    telephoneStation.printSubscribersShortInfo();
    cout << endl;
    // Виводимо повну інформацію про абонентів
    telephoneStation.printSubscribersFullInfo();
    cout << endl;
    // Розраховуємо загальну заборгованість, кількість боржників та виводимо повну інформацію про боржників
    telephoneStation.calculateAndAnalyzeDebts();
    cout << endl;
    return 0;
}