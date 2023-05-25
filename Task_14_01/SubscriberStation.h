#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include"Subscriber.h"
using namespace std;

class SubscriberStation
{
	friend istream& operator>>(istream& is, SubscriberStation& current)
	{
		cout << "Enter number of subscribers: ";
		int size; is >> size;
		Subscriber temp;
		ifstream file("list.txt");
		for (int i = 0; i < size; i++)
		{
			current.list.push_back(temp);
		}
		for (int i = 0; i < size; i++)
		{
			file >> current.list[i];
		}
		file.close();
		return is;
	}
	friend ostream& operator<<(ostream& os, SubscriberStation& current)
	{
		for (int i = 0; i < current.list.size(); i++)
		{
			os << current.list[i];
		}
		return os;
	}

private:
	string name;
	vector<Subscriber> list;
public:
	SubscriberStation() : name(""), list(0) {};
	void changeInfo();
	void summaryDebt();
	void findbyAdress();
	void findbyDebt();
	void deleteSubscriber();
	void addSubscriber();
	void menu();
};

void SubscriberStation::changeInfo()
{
	cout << "Select which field to change: ";
	cout << endl << "1. ID " << endl << "2. ADDRESS " << endl << "3. PHONE NUMBER " << endl << "4. DEBT STATE " << endl;
	int option; cin >> option;
	for (int i = 0; i < list.size(); i++)
	{
		cout << i + 1 << ". ---------------------------------" << endl;
		cout << list[i];
		cout << endl;
	}
	cout << endl << "Select subscriber: ";
	int pos; cin >> pos;
	--pos;
	switch (option)
	{
	case 1: {
		cout << "Enter new ID: ";
		int set; cin >> set;
		list[pos].setID(set);
		break;
	}
	case 2: {
		cout << "Enter new adress: ";
		string set; cin >> set;
		list[pos].setADRESS(set);
		break;
	}
	case 3: {
		cout << "Enter new phone number: ";
		string set; cin >> set;
		list[pos].setNUMBER(set);
		break;
	}
	case 4: {
		cout << "Enter new debt: ";
		int set; cin >> set;
		list[pos].setDEBT(set);
		break;
	}
	default:
		cout << "Invalid option!" << endl;
		break;
	}
}

void SubscriberStation::summaryDebt()
{
	int debt{ 0 };
	for (int i = 0; i < list.size(); i++)
	{
		debt += list[i].getDEBT();
	}
	cout << endl << "Summary debt equal: " << debt << endl;
}

void SubscriberStation::findbyAdress()
{
	cout << endl << "Enter adress you need to find: ";
	string adress; cin >> adress;
	for (int i = 0; i < list.size(); i++)
	{
		if (adress == list[i].getADRESS())
		{
			cout << "Subscriber with adress " + adress;
			cout << endl << list[i] << endl;
		}
	}
}

void SubscriberStation::findbyDebt()
{
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].getDEBT() < 0)
		{
			cout << "Subscriber with debt: ";
			cout << endl << list[i] << endl;
		}
	}
}

void SubscriberStation::deleteSubscriber()
{
	cout << endl;
	for (int i = 0; i < list.size(); i++)
	{
		cout << i + 1 << ". ---------------------------------" << endl;
		cout << list[i];
		cout << endl;
	}
	cout << endl << "Which one you wanna to delete: ";
	int option; cin >> option;
	if (option > 0 && option <= list.size())
	{
		auto it = list.begin() + option - 1;
		list.erase(it);
		cout << "Subscriber " << option << " has been deleted" << endl;
	}
	else
	{
		cout << "Invalid option" << endl;
	}
}

void SubscriberStation::addSubscriber()
{
	cout << "Enter number of subscribers you wanna to add: ";
	int num, it{ 0 }, size; cin >> num;
	size = list.size();
	Subscriber temp;
	ifstream file("list.txt");
	while (it != size) { file >> temp; it++; }
	for (int i = 0; i < num; i++)
	{
		file >> temp;
		list.push_back(temp);
	}
	file.close();
}
void SubscriberStation::menu() {
	int choice;
	cout << "Choose an action: \n";
	cout << "0.Exit\n";
	cout << "1.Add Subscriber\n";
	cout << "2.Delete Subscriber\n";
	cout << "3.Find by debt\n";
	cout << "4.Find by adress\n";
	cout << "5.Summary by debt\n";
	cout << "6.Change info\n";
	cout << "Your choise: ";
	cin >> choice;
	switch (choice) {
	case 1:
		addSubscriber();
		break;
	case 2:
		deleteSubscriber();
		break;
	case 3:
		findbyDebt();
		break;
	case 4:
		findbyAdress();
		break;
	case 5:
		summaryDebt();
		break;
	case 6:
		changeInfo();
		break;
	default:
		cout << "Exit" << endl;
		break;
	}
}