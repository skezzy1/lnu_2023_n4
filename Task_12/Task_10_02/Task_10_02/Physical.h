#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <algorithm>
using namespace std;
class Physical : public Subscriber {
private:
    string Surname, Name, middleName;
public:
    Physical() : Subscriber() {};
    Physical(string accountNumber, string phoneNumber, int debtInfo, string address, float discount, string surname, string name, string middleName) : Subscriber(accountNumber, phoneNumber, debtInfo, address, discount), Surname(surname), Name(name), middleName(middleName) {};
    int getDebt() override {
        if (debtInfo > 10000) {
            return debtInfo;
        }
        return debtInfo * (1 - discount);
    }
    void getAddress() override {
        cout << "Адреса фізичної особи: " << address << endl;
    }
    void getPhoneNumber() override {
        cout << "Номер телефону фізичної особи: " << phoneNumber << endl;
    }
    void getAccountNumber() override {
        cout << "Рахунок фізичної особи: " << accountNumber << endl;
    }
    float getDiscount() override {
        return discount;
    }
    void divideName() {
        string fullName = Surname + " " + Name + " " + middleName;
        int spaceIndex = fullName.find(" ");
        cout << "Прізвище: " << fullName.substr(0, spaceIndex) << endl;
        fullName.erase(0, spaceIndex + 1);
        spaceIndex = fullName.find(" ");
        cout << "Ім'я: " << fullName.substr(0, spaceIndex) << endl;
        fullName.erase(0, spaceIndex + 1);
        cout << "По-батькові: " << fullName << endl;
    }
};