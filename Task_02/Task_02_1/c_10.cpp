#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	// A start(must be <=b), B the end, H steps
    float a, b, h, y;
    cout << "Enter a, b and h: ";
    cin >> a >> b >> h;
    float x = a;
    int count = 0;
    int n = 0;
    float max = 0;
    y = max;
    while (x <= b) {
        if (h <= 0) {
            cout << "Please enter a bigger than null number: " << endl;
            break;
        }
        y = x * sin(x);
        cout << "x = " << x << ";\t y = " << y << "\t\tX*Y"<< x*y <<endl;
        if (y < 0.0) {
            count += 1;
        }
        if (max < y) {
            max = y;
        }
        x = x + h;
        
    }
    cout << "Number of negative numbers: " << count << endl;
    cout << "The maximum value of the function: " << max << endl;
    return 0;
}
