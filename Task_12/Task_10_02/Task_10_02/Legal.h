#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <algorithm>
using namespace std;

class Legal : public Subscriber {
private:
    int countOfAbounents;
public:
    Legal() : Subscriber() {};
    Legal(string accountNumber, string phoneNumber, int debtInfo, string address, float discount, vector<int> count) : Subscriber(accountNumber, phoneNumber, debtInfo, address, discount, countOfNumbers(count)) {};
    int getDebt() override {
        return debtInfo * (1 + 0.05 * countOfNumbers.size()); // розрахунок з урахуванням знижки
    }
    void getAddress() override {
        cout << "Адреса юридичної особи: " << address << endl;
    }
    void getPhoneNumber() override {
        cout << "Номер телефону юридичної особи: " << phoneNumber << endl;
    }
    void getAccountNumber() override {
        cout << "Рахунок юридичної особи: " << accountNumber << endl;
    }
    float getDiscount() override {
        return discount;
    }
};