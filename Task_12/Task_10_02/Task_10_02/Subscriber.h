#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <algorithm>

class Subscriber {
    friend istream& operator>>(istream&, Subscriber&);
    friend ostream& operator<<(ostream&, Subscriber&);
protected:
    string accountNumber;
    string phoneNumber;
    int debtInfo;
    string address;
    float discount;
public:
    Subscriber();
    Subscriber(string accountNumber, string phoneNumber, int debtInfo, string address, float discount);
    Subscriber(const Subscriber& other);
    friend istream& operator>>(istream& is, Subscriber& p);
    friend ostream& operator<<(ostream& os, const Subscriber& p);
    //getters
    int getDebt();
    string getAddress();
    string getPhoneNumber();
    string getAccountNumber();
    float getDiscount();
    //Setters
    void setDebt(int Debt);
    void setAddress(string Addr);
    void setPhoneNumber(string phoneN);
    void setAccountNumber(string accountN);
    void changeDebt();
    void changeDiscount();
    virtual istream& input(istream&);
    virtual ostream& output(ostream&);
};
