#include <iostream>
using namespace std;

int main(){
    int n, m = 0;
    cout << "n = ";
    cin >> n;
    int** Arr;
    Arr = new int* [n];
    for (int i = 0; i < n; i++) Arr[i] = new int[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            Arr[i][j] = 0;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - m; j++)
            Arr[i][j] = i + j + 1;
        m++;
    }
    cout << "Matrix " << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cout << Arr[i][j] << " ";
        cout << endl;
    }
    /*Перший елемент*/
   	cout << Arr[0][0] << "\n"; 
   	/*Головна діагональ матриці*/
   	for(int i=0; i<n; i++){
   		cout << Arr[i][i];	
	}
	cout << "\n";	
	/*Перший рядок*/
   	for(int j=0; j<n; j++){
   		cout << Arr[0][j];
	}
	cout << "\n";	
	/*Другий стовпчик*/
	for(int i=0; i<n; i++){
		cout << Arr[i][1];
	}
	/*Бічна діагональ матриці*/
	cout << "\n";
	int a = 1;
	for(int i=0; i<n; i++){
		cout << Arr[i][n-a];
		a++;
	}
	/*Нижня діагональ матриці(не варто записувати)*/
	for(int i=0; i<n-1; i++){
   		cout << Arr[i-1][i];	
	}
    delete[] Arr;
    return 0;
}
