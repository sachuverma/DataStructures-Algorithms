#include <iostream>
#include <string>
using namespace std;

// this c++ program takes a string and number of rows to output a new zigzag pattern.

string ZigZag(string _str, int _rows) {
    if (_rows == 1)
        return _str; // No work to be done.
    string result = ""; // Set string to empty to begin the pattern
    int step = 2 * (_rows - 1);
    // loop through the string and append the result of each step
    for (int i = 0; i < _rows; i++) {
        int index = 0;
        while (index + i < _str.size()) {
            result += _str[index + i];
            if (i != 0 && i != _rows - 1 && index - i + step < _str.size())
                result += _str[index + step - i];
            index += step;
        }
    }
    return result;
}

int main() {
    string test = "Harry-Potter";
    cout <<  ZigZag(test, 1) << endl;
    cout <<  ZigZag(test, 2) << endl;
    cout <<  ZigZag(test, 3) << endl;
    cout <<  ZigZag(test, 4) << endl;
    cout <<  ZigZag(test, 5) << endl;
    cout <<  ZigZag(test, 6) << endl;
    cout <<  ZigZag(test, 7) << endl;
    cout <<  ZigZag(test, 8) << endl;
    cout <<  ZigZag(test, 9) << endl;
    cout <<  ZigZag(test, 10) << endl;
    cout <<  ZigZag(test, 11) << endl;
    cout <<  ZigZag(test, 12) << endl; // 12 outputs the same input for this string. intersting! :)
} 