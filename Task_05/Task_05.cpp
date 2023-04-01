#include <iostream>
using namespace std;
void CheckOfSquare(int array[], int n, int m) {
	for (int i = 0; i < n; i++)
	{
		if (array[i] == (m * m)) {
			cout << array[i];
		}
		else if (array[i] != (m * m)) {
			cout << "The massive doesn't have a square" << endl;
		}
		else {
			cout << "Error" << endl;
		}
	}
}
int main(){
	int n, m;
	cout << "Enter array size: \0";
	cin >> n;
	cout << "Enter the number: \0";
	cin >> m;
	int* array = new int[n];
	cout << "Enter value of massive: \0";
	for (int i = 0; i < n; i++){
		cin >> array[i];
	}
	CheckOfSquare(array, n, m);
	delete[] array;
	return 0;
}

