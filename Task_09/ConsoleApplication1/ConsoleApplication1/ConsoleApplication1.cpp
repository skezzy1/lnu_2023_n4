#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "ukr");
    ifstream file("input.txt");
    vector<double> numbers;
    double sum = 0;
    double number;
    while (file >> number) {
        numbers.push_back(number);
        sum += number;
    }
    double mean = sum / numbers.size();
    int count = 0;
    for (double num : numbers) {
        if (num < mean) {
            count++;
        }
    }
    cout << "Кiлькiсть елементiв файлу, якi меншi за середнє арифметичне: " << count << endl;
    return 0;
}