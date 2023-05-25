#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <algorithm>
#include "Subscriber.h"
#include "Legal.h"
#include "Physical.h"
#include "Functions.h"
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(65001);
    int n; cout << "Введіть кількість абонентів: "; cin >> n;
    vector<Subscriber> abonents(n);
    cout << endl;
    for (int i = 0; i < n; i++) {
        cin >> abonents[i];
        cout << endl;
    }
        abonents[i].changeDiscount(0.2);
        abonents[i].changeDebt(abonents[i].getDiscount());
        cout << "Стан заборгованості після застосування пільги: " << abonents[i].getDebt() << endl;
        cout << endl;
    }
    cin.get();
    return 0;
}

