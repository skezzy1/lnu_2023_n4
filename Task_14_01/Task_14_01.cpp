#include<iostream>
#include<fstream>
#include<windows.h>
#include<vector>
#include"Subscriber.h"
#include"SubscriberStation.h"
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SubscriberStation comp;
	ifstream comp1;
	comp1.exceptions(ifstream::badbit | ifstream::failbit);
	try {
		cout << "Спроба відкрити файл!" << endl;
		comp1.open("list.txt");
		cout << "Файл успішно відкритий!" << endl;
	}
	catch (const ifstream::failure& ex) {
		cout << ex.what() << endl;
		cout << ex.code() << endl;
		cout << "Помилка відкриття файлу!" << endl;
	}
	cin >> comp;
	cout << comp;
	comp.menu();
	cout << comp;
	return 0;
}