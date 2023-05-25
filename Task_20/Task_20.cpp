#include <iostream>
#include <stack>
#include <string>
#include <windows.h>

using namespace std;
bool balanced(string expr) {
    stack<char> s;
    char x;
    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {
            s.push(expr[i]);
            continue;
        }
        if (s.empty()) {
            return false;
        }

        switch (expr[i]) {
        case ')':
            x = s.top();
            s.pop();
            if (x == '[' || x == '{') {
                return false;
            }
            break;
        case ']':
            x = s.top();
            s.pop();
            if (x == '(' || x == '{') {
                return false;
            }
            break;
        case '}':
            x = s.top();
            s.pop();
            if (x == '(' || x == '[') {
                return false;
            }
            break;
        }
    }
    return s.empty();
}
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string expr = "{[()]}";
    if (balanced(expr)) {
        cout << "Дужки збалансовані" << endl;
    }
    else {
        cout << "Дужки не збалансовані" << endl;
    }
    return 0;
}