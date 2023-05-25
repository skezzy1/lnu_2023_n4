#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
using namespace std;
int main() {
    ifstream file("input.txt");
    string text;
    getline(file, text, '.');

    unordered_set<char> unique_chars;
    string word;

    for (char c : text) {
        if (isspace(c)) {
            bool all_different = true;
            for (char c2 : word) {
                if (unique_chars.count(c2) > 0) {
                    all_different = false;
                    break;
                }
                unique_chars.insert(c2);
            }
            if (all_different) {
                cout << word << std::endl;
            }
            word.clear();
            unique_chars.clear();
        }
        else {
            word.push_back(c);
        }
    }

    return 0;
}