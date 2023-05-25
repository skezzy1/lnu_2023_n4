#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <algorithm>
#include "Subscriber.h"
using namespace std;

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
Subscriber::Subscriber(const Subscriber& other) {
    this->accountNumber = other.accountNumber;
    this->phoneNumber = other.phoneNumber;
    this->debtInfo = other.debtInfo;
    this->address = other.address;
    this->discount = other.discount;
}
//getters
string Subscriber::getAccountNumber() { return accountNumber; }
string Subscriber::getPhoneNumber() { return phoneNumber; }
int Subscriber::getDebt() { return debtInfo; }
string Subscriber::getAddress() { return address; }
float Subscriber::discount() { return discount; }
//setters
void Subscriber::setAccountNumber(string accountN) { accountN = accountNumber; }
void Subscriber::setPhoneNumber(string phoneN) { phoneN  = phoneNumber; }
void Subscriber::setDebt(int Debt) { Debt = debtInfo; }
void Subscriber::setAddress(string addr) { addr = address; }
istream& Subscriber::input(istream& is) {
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

ostream& Subscriber::output(ostream& os) {
    os << "==============================================" << endl;
    os << "����� �������: " << p.accountNumber << endl;
    os << "����� ��������: " << p.phoneNumber << endl;
    os << "���� �������������: " << p.debtInfo << endl;
    os << "������: " << p.address << endl;
    os << "����� ����� (� ��������): " << p.discount << endl;
    return os;
}