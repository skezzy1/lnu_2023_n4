#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct sportsman {
    int mark = 1;
    string surname = "error";
};

void InputSportsmanInfo(ifstream& file, sportsman* list, int sportsmen);
void OutPutSportsmanInfo(ofstream& file, sportsman* list, int sportsmen);
void TheBestMark(ofstream& file, sportsman* list, int sportsmen);

int main() {
    string iPath = "input.txt";
    string oPath = "output.txt";
    ifstream iFile(iPath, ios::in);
    if (!iFile.is_open()) { cout << "Error" << "\n"; }
    int sportsmen;
    iFile >> sportsmen;
    sportsman* list = new sportsman[sportsmen];
    InputSportsmanInfo(iFile, list, sportsmen);
    iFile.close();
    ofstream oFile(oPath, ios::out);
    OutPutSportsmanInfo(oFile, list, sportsmen);
    TheBestMark(oFile, list, sportsmen);
    oFile.close();
    delete[] list;
}

void InputSportsmanInfo(ifstream& file, sportsman* list, int sportsmen) {
    if (!file.is_open()) { cout << "File is not open" << "\n"; }
    for (int i = 0; i < sportsmen; i++) {
        file >> list[i].surname >> list[i].mark;
    }
}

void OutPutSportsmanInfo(ofstream& file, sportsman* list, int sportsmen) {
    if (!file.is_open()) { cout << "File is not open" << "\n"; }
    file << "List of sportsmen:\n";
    for (int i = 0; i < sportsmen; i++) {
        file << list[i].surname << "\n" << list[i].mark << "\n";
    }
    cout << "\n";
}

void TheBestMark(ofstream& file, sportsman* list, int sportsmen) {
    if (!file.is_open()) { cout << "File is not open" << "\n"; }
    int max = list[0].mark;
    int pos = 0;
    for (int i = 0; i < sportsmen; i++) {
        if (max < list[i].mark) {
            max = list[i].mark;
        }
    }
    file << "Winner: " << list[pos].surname;
}
