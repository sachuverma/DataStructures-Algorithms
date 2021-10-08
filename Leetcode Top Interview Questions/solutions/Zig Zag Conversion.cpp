#include <iostream>
#include <string>
using namespace std;

/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I

Example 3:

Input: s = "A", numRows = 1
Output: "A"

 

Constraints:

    1 <= s.length <= 1000
    s consists of English letters (lower-case and upper-case), ',' and '.'.
    1 <= numRows <= 1000
*/


class Solution {
    public:
    string zig_zag(string _str, int _rows) {
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
};

// This is just so you can run the code in your local environmont
int main() {
    Solution output;
    string test = "Harry-Potter";
    cout <<  output.zig_zag(test, 1) << endl;
    cout <<  output.zig_zag(test, 2) << endl;
    cout <<  output.zig_zag(test, 3) << endl;
    cout <<  output.zig_zag(test, 4) << endl;
    cout <<  output.zig_zag(test, 5) << endl;
    cout <<  output.zig_zag(test, 6) << endl;
    cout <<  output.zig_zag(test, 7) << endl;
    cout <<  output.zig_zag(test, 8) << endl;
    cout <<  output.zig_zag(test, 9) << endl;
    cout <<  output.zig_zag(test, 10) << endl;
    cout <<  output.zig_zag(test, 11) << endl;
    cout <<  output.zig_zag(test, 12) << endl; // 12 outputs the same input for this string. intersting! :)
} 