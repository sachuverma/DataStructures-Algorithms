/*
Complex Number Multiplication
=============================

A complex number can be represented as a string on the form "real+imaginaryi" where:

real is the real part and is an integer in the range [-100, 100].
imaginary is the imaginary part and is an integer in the range [-100, 100].
i2 == -1.
Given two complex numbers num1 and num2 as strings, return a string of the complex number that represents their multiplications.

Example 1:
Input: num1 = "1+1i", num2 = "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.

Example 2:
Input: num1 = "1+-1i", num2 = "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
 
Constraints:
num1 and num2 are valid complex numbers.
*/

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int r1 = stoi(a.substr(0, a.find('+')+1));
        int r2 = stoi(b.substr(0, b.find('+')+1));
        
        int c1 = stoi(a.substr(a.find('+')+1));
        int c2 = stoi(b.substr(b.find('+')+1));
        
        return to_string(r1*r2 - c1*c2) + "+" + to_string(r1*c2 + r2*c1) + "i";
    }
};