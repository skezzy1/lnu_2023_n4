#include <iostream>
#include <cmath>
using namespace std;
/* 1.	Дано 3 числа  a,  b,  c. Визначити, яке з них дорівнює  d. Якщо жодне з чисел не рівне  d, то знайти  max{d-a, d-b, d-c}.*/
int main() {
	double a, b, c, d;
	cout << "Enter A: ";
	cin >> a;
	cout << "Enter B: ";
	cin >> b;
	cout << "Enter C: ";
	cin >> c;
	cout << "Enter D: ";
	cin >> d;
	if (a == d) { cout << "A = D: " << a; }
	else if (b == d) { cout << "B = D: " << b; }
	else {
		if (c == d) { cout << "C = D: " << c;}
		else if((a && b && c)!=d){cout << max(d-a, max(d-b, d-c));}
		else { cout << "Nothing is equal to d. Result is: ";}
	}
}
