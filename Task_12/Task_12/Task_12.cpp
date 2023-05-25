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
       cout << "��'�: " << name << ", ������: " << address << ", �������������: " << debt << " ���" << endl;
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
                cout << "�������� " << name << " �������� � ������ ��������." << endl;
                return;
            }
        }
        cout << "�������� � ��'�� " << name << " �� ��������." << endl;
    }

    void printSubscribersShortInfo() const {
        cout << "������ �������� (��������� ����������):" << endl;
        for (const auto& subscriber : subscribers) {
            cout << "��'�: " << subscriber.getName() << ", ������: " << subscriber.getAddress() << endl;
        }
    }

    void printSubscribersFullInfo() const {
        cout << "������ �������� (����� ����������):" << endl;
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

        cout << "�������� �������������: " << totalDebt << " ���" << endl;
        cout << "ʳ������ ��������: " << numDebtors << endl;

        cout << "����� ���������� ��� ��������:" << endl;
        for (const auto& subscriber : subscribers) {
            if (subscriber.getDebt() > 0) {
                subscriber.printFullInfo();
            }
        }
    }
    void searchSubscriberByAddress(const string& address) const {
        cout << "���������� ������ �������� �� ������� " << address << ":" << endl;
        bool found = false; for (const auto& subscriber : subscribers) { 
            if (subscriber.getAddress() == address) 
            {
                subscriber.printFullInfo(); found = true;
            } 
        }
        if (!found) {
            cout << "�������� �� �������� ������� �� ��������." << endl;
        }
    }
    void searchDebtors() const {
        cout << "������ �������� � �������������:" << endl;
        bool found = false;
        for (const auto& subscriber : subscribers) {
            if (subscriber.getDebt() > 0) {
                subscriber.printFullInfo();
                found = true;
            }
        }

        if (!found) {
            cout << "���� �������� � �������������." << std::endl;
        }
    }
private:
    std::vector<Subscriber> subscribers;
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string SubscribersFile("file.txt");
    Subscriber subscriber1("��������", "���. �������� 1", 150.0);
    Subscriber subscriber2("������", "���. ������ 10", 0.0);
    Subscriber subscriber3("�������", "���. �������", 9.0);
    TelephoneStation telephoneStation;
    // ������ �������� �� ��������� �������
    telephoneStation.addSubscriber(subscriber1);
    telephoneStation.addSubscriber(subscriber2);
    telephoneStation.addSubscriber(subscriber3);
    cout << endl;
    // �������� ��������� ���������� ��� ��������
    telephoneStation.printSubscribersShortInfo();
    cout << endl;
    // �������� ����� ���������� ��� ��������
    telephoneStation.printSubscribersFullInfo();
    cout << endl;
    // ����������� �������� �������������, ������� �������� �� �������� ����� ���������� ��� ��������
    telephoneStation.calculateAndAnalyzeDebts();
    cout << endl;
    return 0;
}