/*
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 
Constraints:
    1 <= n <= 45
*/

// Fastest solution using Fast Fibonacci technique (O(log n))
class Solution {
public:
    unordered_map <int,int> F;

    int f(int n)
    {
        if (F.find(n) != F.end()) return F[n];
        int k = (n>>1);

        if (n&1)
            return F[n] = (f(k-1)*f(k) + f(k)*f(k+1));
        else
            return F[n] = (f(k-1)*f(k-1) + f(k)*f(k));
    }
    
    int climbStairs(int n)
    {
        F[0] = F[1] = 1;
        return f(n);
    }
};