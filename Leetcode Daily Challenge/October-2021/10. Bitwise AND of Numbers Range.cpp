/*
Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

 
Example 1:

Input: left = 5, right = 7
Output: 4


Example 2:

Input: left = 0, right = 0
Output: 0


Example 3:

Input: left = 1, right = 2147483647
Output: 0
 

Constraints:

0 <= left <= right <= 231 - 1
*/

class Solution {
public:
    int pos(int x) {
        int cnt = -1;
        
        while(x) {
            x>>=1;
            cnt++;
        }
        
        return cnt;
    }
    
    int rangeBitwiseAnd(int l, int r) {
        int res = 0;
        
        while(l&&r) {
            int p1 = pos(l);
            int p2 = pos(r);
            
            if(p1!=p2)
                break;
            
            int val = (int)pow(2,p1);
            res+=val;
            
            l = l-val;
            r = r-val;
        }
        
        return res;
    }
};