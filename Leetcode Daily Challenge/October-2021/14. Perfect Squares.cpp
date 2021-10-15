/*
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

 

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.


Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
 

Constraints:

1 <= n <= 104
*/

class Solution {
public:
    int numSquares(int n) {
        vector<int> count(n+1,INT_MAX);
        
        count[0]=0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j*j<=i;j++) {
                count[i]=min(count[i],count[i-j*j]+1);
            }
        }
        
        return count[n];
            
        
    }
};