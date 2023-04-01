#include <iostream>
#include <string>
using namespace std;
struct sportsman {
    int mark1, mark2, mark3, mark4, mark5, number, age, result;
    string surname, sport;
};
sportsman input_sportsman(int num) {
    sportsman newStd;
    newStd.number = num;
    cout << "Enter Surname:";
    if (cin.peek() == '\n')
        cin.ignore();
    getline(cin, newStd.surname);
    cout << "Enter age: ";
    cin >> newStd.age;
    cout << "Enter mark of football: ";
    cin >> newStd.mark1;
    cout << "Enter mark of soccer: ";
    cin >> newStd.mark2;
    cout << "Enter mark of voleyball: ";
    cin >> newStd.mark3;
    cout << "Enter mark of box: ";
    cin >> newStd.mark4;
    cout << "Enter mark of swimming: ";
    cin >> newStd.mark5;
    newStd.result = newStd.mark1 + newStd.mark2 + newStd.mark3 + newStd.mark4 + newStd.mark5;
    cout << endl;
    return newStd;
}
void OutputSportsmanInfo(sportsman n) {
    cout << "Surname:" << n.surname << endl;
    cout << "Age: " << n.age << endl;
    cout << "Mark of football: " << n.mark1 << endl;
    cout << "Mark of soccer: " << n.mark2 << endl;
    cout << "Mark of voleyball: " << n.mark3 << endl;
    cout << "Mark of box: " << n.mark4 << endl;
    cout << "Mark of hockey: " << n.mark5 << endl;
}
void inputGroupOfSportsmen(sportsman*& group, int n) {
    for (int i = 0; i < n; i++)
    {
        cout << "Sportsmen number " << i + 1 << "\n";
        group[i] = input_sportsman(i);
    }
}
void OutPutGroupOfSportsmen(sportsman* group, int n) {
    cout << endl << "Group" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\n";
        cout << "Sportsman number:" << i + 1 << endl;
        OutputSportsmanInfo(group[i]);
    }
}
sportsman TheBestMark(sportsman* group, int n) {
    sportsman thebestresult = group[0];
    for (int i = 0; i < n; i++) {
        if (group[i].result > group[0].result) {
            cout << "The best result has: " << group[i].surname;
            thebestresult = group[i];
        }
    }
    return thebestresult;
}
int main()
{
    int n;
    cout << "Input size of group: \0";
    cin >> n;
    sportsman* group = new sportsman[n];
    inputGroupOfSportsmen(group, n);
    OutPutGroupOfSportsmen(group, n);
    cout << "\n";
    TheBestMark(group, n);
    cout << "\n";
    delete[] group;
    return 0;
}
