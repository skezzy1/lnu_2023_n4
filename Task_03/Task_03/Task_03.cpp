#include <iostream> 
using namespace std;
int main()
{
    int SizeOfMassive;
    cout << "Enter size of massive: ";
    cin >> SizeOfMassive;
    int* pArray = new int[SizeOfMassive];
    cout << "Enter value of massive: ";
    for (int i = 0; i < SizeOfMassive; i++){
        cin >> pArray[i];
        cout << pArray[i]*pArray[i] << " ";
    }

  /*  int m, l;
    cout << "M: ";
    cin >> m;
    cout << "L: ";
    cin >> l;
    if (l > 0 && l <= m - 1) {
        for (int i = 0; i < SizeOfMassive; i++)
        {
            if (pArray[i] % m == l) {
                cout << pArray[i] << " ";
            }
    }
    system("PAUSE");*/
    return 0;  
}
