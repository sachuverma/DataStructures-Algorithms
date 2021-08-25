/*
Sum of Square Numbers
=====================

Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:
Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5

Example 2:
Input: c = 3
Output: false

Example 3:
Input: c = 4
Output: true

Example 4:
Input: c = 2
Output: true

Example 5:
Input: c = 1
Output: true
 
Constraints:
0 <= c <= 231 - 1
*/

class Solution {
public:
    bool judgeSquareSum(int c) {
        int sqrt_c = sqrt(c);
        if(sqrt_c * sqrt_c == c) return true;
        
        for(int a = 0; a <= sqrt(c); ++a) {
            int b_sq = c - (a*a);
            int b = sqrt(b_sq);
            if(b*b == b_sq) return true;
        }
        
        return false;
    }
};