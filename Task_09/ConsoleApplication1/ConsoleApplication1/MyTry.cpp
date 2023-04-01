#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string FileName = "input.txt";
	setlocale(LC_ALL, "ukr");
	ifstream file(FileName);
	vector<double> numbers;
	double sum = 0;
	double number;
	while(file >> number) {
		numbers.push_back(number);
		sum += number;
	}
	double mean = sum / numbers.size();
	int count = 0;
	for (double num : numbers)
	{
		if (num < mean)
		{
			count++;
		}
	}
	cout << "Кiлькiсть елементiв файлу, якi меншi за середнє арифметичне: " << count << endl; 
	return 0;
}