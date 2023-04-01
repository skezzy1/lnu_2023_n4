#include <iostream>
#include <string>
#include <locale>
#include <windows.h>
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
    // �������� �-� ���� � �����
    bool checkPhoneNumber() {
        if (phoneNumber.length() != 12) {
            return false;
        }
        string code = phoneNumber.substr(0, 5);
        if (code != "38067" && code != "38068" && code != "38096" && code != "38097" && code != "38098") {
            return false;
        }
        return true;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, "ukr");
    Subscriber p;
    cin >> p;
    cout << p;
    if (!p.checkPhoneNumber()) {
        cout << "����� �������� � ������������" << endl;
    }
    p.changeDiscount(0.2);
    p.changeDebt(p.getDiscount());
    cout << "���� ������������� ���� ������������ �����:" << p.getDebt() << endl;
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
    cout << "������ ����� �������: ";
    is >> p.accountNumber;
    cout << "������ ����� ��������: ";
    is >> p.phoneNumber;
    cout << "������ ���� �������������: ";
    is >> p.debtInfo;
    cout << "������ ������:";
    is.ignore();
    getline(is, p.address);
    cout << "������ ����� ����� (� ��������): ";
    is >> p.discount;
    cout << endl;
    return is;
}

ostream& operator<<(ostream& os, const Subscriber& p) {
    os << "����� �������: " << p.accountNumber << endl;
    os << "����� ��������: " << p.phoneNumber << endl;
    os << "���� �������������: " << p.debtInfo << endl;
    os << "������: " << p.address << endl;
    os << "����� ����� (� ��������): " << p.discount << endl;
    return os;
}