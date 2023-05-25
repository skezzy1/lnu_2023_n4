#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <algorithm>
using namespace std;

class Subscriber {
protected:
    int debtInfo;
    string address, phoneNumber, accountNumber;
    float discount;
public:
    Subscriber();
    Subscriber(string accountNumber, string phoneNumber, int debtInfo, string address, float discount);
    friend istream& operator>>(istream& is, Subscriber& p);
    friend ostream& operator<<(ostream& os, const Subscriber& p);
    //Setters
    void setDebt(int debt) {
        debtInfo = debt;
    }
    void setAddress(string adr) {
        address = adr;
    }
    void setPhoneNumber(string phoneNum) {
        phoneNumber = phoneNum;
    }
    void setAccountNumber(string accountNum) {
        accountNumber = accountNum;
    }
    void changeDebt(float discount) {
        debtInfo *= (1 - discount);
    }
    void changeDiscount(float newDiscount) {
        discount = newDiscount;
    }
    //Getters
    int getDebt() const {
        return debtInfo;
    }
    string getAddress() const {
        return address;
    }
    string getPhoneNumber() const {
        return phoneNumber;
    }
    string getAccountNumber() const {
        return accountNumber;
    }
    float getDiscount() const {
        return discount;
    }
    bool checkPhoneNumber() {
        string code = phoneNumber.substr(0, 5);
        if (code != "38067" && code != "38068" && code != "38096" && code != "38097" && code != "38098" && phoneNumber.length() != 12) {
            return false;
        }
        return true;
    }
    bool operator<(const Subscriber& other) const {
        return address < other.address;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, "ukr");
    int n; cout << "Введіть кількість абонентів: "; cin >> n;
    vector<Subscriber> abonents(n);
    cout << endl;
    for (int i = 0; i < n; i++) {
        cin >> abonents[i];
        cout << endl;
    }
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
        abonents[i].changeDiscount(0.2);
        abonents[i].changeDebt(abonents[i].getDiscount());
        cout << "Стан заборгованості після застосування пільги: " << abonents[i].getDebt() << endl;
        cout << endl;
    }
    cin.get();
    return 0;
}

Subscriber::Subscriber() {
    accountNumber = "";
    phoneNumber = "";
    debtInfo = 0;
    address = "";
    discount = 0.0;
}

Subscriber::Subscriber(string accountNumber, string phoneNumber, int debtInfo, string address, float discount) {
    this->accountNumber = accountNumber;
    this->phoneNumber = phoneNumber;
    this->debtInfo = debtInfo;
    this->address = address;
    this->discount = discount;
}

istream& operator>>(istream& is, Subscriber& p) {
    cout << "Введіть номер рахунку: ";
    is >> p.accountNumber;
    cout << "Введіть номер телефону: ";
    is >> p.phoneNumber;
    cout << "Введіть стан заборгованості: ";
    is >> p.debtInfo;
    cout << "Введіть адресу:";
    is.ignore();
    getline(is, p.address);
    cout << "Введіть розмір пільги (у відсотках): ";
    is >> p.discount;
    cout << endl;
    return is;
}

ostream& operator<<(ostream& os, const Subscriber& p) {
    os << "==============================================" << endl;
    os << "Номер рахунку: " << p.accountNumber << endl;
    os << "Номер телефону: " << p.phoneNumber << endl;
    os << "Стан заборгованості: " << p.debtInfo << endl;
    os << "Адреса: " << p.address << endl;
    os << "Розмір пільги (у відсотках): " << p.discount << endl;
    return os;
}