#include <iostream>
#include <string>
struct pupile{
	string surname;
	int height;
};
pupile InputPupile(int num) {
    pupile newStd;
    newStd.number = num;
    cout << "Enter Surname: \0";
    if (cin.peek() == '\n')
        cin.ignore();
    getline(cin, newStd.surname);
    cout << "Enter height: \0";
    cin >> newStd.height;
    return newStd;
}
void OutPutPupileInfo(pupile n){
	cout << "Surname:" << n.surname << endl;
    cout << "Height:" << n.height << endl;
}
pupile TheHeigestPupile(pupile* group, int n) {
    pupile theheigest = group[0];
    for (int i = 0; i < n; i++) {
        if (group[i].height > group[0].height) {
            cout << "The heigest: " << group[i].surname;
            theheigest = group[i];
        }
    }
    return theheigest;
}
pupile TheLowestPupile(pupile* group, int n){
	pupile thelowest = group[0];
    for (int i = 0; i < n; i++) {
        if (group[i].height < group[0].height) {
            cout << "The heigest: " << group[i].surname;
            thelowest = group[i];
        }
    }
    return thelowest;
}
int main() {
	int SizeOfGroup; cout << "Input size of group: \0"; cin >> SizeOfGroup;
    pupile* group = new pupile[n];
    InputPupile(group, n);
    OutPutPupileInfo(group, n);
    cout << "\n";
    TheHeigestPupile(group, n);
    cout << "\n";
    TheLowestPupile(group, n);
    cout << "\n";
    delete [] group;
	return 0;
}
