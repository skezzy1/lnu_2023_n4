#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <algorithm>

sort(abonents.begin(), abonents.end());
for (int i = 0; i < n; i++) {
    cout << abonents[i] << endl;
    if (!abonents[i].checkPhoneNumber()) {
        cout << "Номер телефону є неправильним" << endl;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (abonents[j].getDebt() < abonents[j + 1].getDebt()) {
                swap(abonents[j], abonents[j + 1]);
            }
        }
}
bool checkPhoneNumber() {
    if (phoneNumber.length() != 12) {
         cout << "Номер телефону не правильний" << endl;
         return false;
    }
    string code = phoneNumber.substr(0, 5);
    if (code != "38067" && code != "38068" && code != "38096" && code != "38097" && code != "38098") {
        cout << "Номер телефону не правильний" << endl;
        return false;
    }
    return true;
}
bool operator<(const Subscriber & other) const {
     return address < other.address;
}
cin.get()
{
    return cin .();
}