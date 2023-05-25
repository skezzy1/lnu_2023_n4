#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

class Subscriber
{
	friend ifstream& operator>>(ifstream& file, Subscriber& current)
	{
		file >> current.id;
		file >> current.adress;
		file >> current.phone_number;
		file >> current.debt;
		return file;
	}
	friend ostream& operator<<(ostream& os, Subscriber& current)
	{
		os << "Id: " << current.id << endl;
		os << "Addres:  " << current.adress << endl;
		os << "Phone number: " << current.phone_number << endl;
		os << "Debt state: " << current.debt << endl;
		return os;
	}

private:
	int id;
	string adress;
	string phone_number;
	int debt;
public:
	Subscriber() : id(0), debt(0), adress(""), phone_number("") {};
	void setID(int set) { id = set; }
	void setADRESS(string set) { adress = set; }
	void setNUMBER(string set) { phone_number = set; }
	void setDEBT(int set) { debt = set; }
	int getDEBT() { return debt; }
	string getADRESS() { return adress; }
};
