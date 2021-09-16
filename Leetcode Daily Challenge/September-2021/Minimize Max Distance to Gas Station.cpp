/*
Minimize Max Distance to Gas Station
====================================

You are given an integer array stations that represents the positions of the gas stations on the x-axis. You are also given an integer k.

You should add k new gas stations. You can add the stations anywhere on the x-axis, and not necessarily on an integer position.

Let penalty() be the maximum distance between adjacent gas stations after adding the k new stations.

Return the smallest possible value of penalty(). Answers within 10-6 of the actual answer will be accepted.

Example 1:
Input: stations = [1,2,3,4,5,6,7,8,9,10], k = 9
Output: 0.50000

Example 2:
Input: stations = [23,24,36,39,46,56,57,65,84,98], k = 1
Output: 14.00000
 
Constraints:
10 <= stations.length <= 2000
0 <= stations[i] <= 108
stations is sorted in a strictly increasing order.
1 <= k <= 106

Hint #1  
Use a binary search. We'll binary search the monotone function "possible(D) = can we use K or less gas stations to ensure each adjacent distance between gas stations is at most D?"
*/

class Solution {
public:
    bool valid(vector<int>& A, int k, double D) {
        int used = 0;
        for (int i = 0; i < A.size() - 1; ++i)
            used += (int) ((A[i+1] - A[i]) / D);
        return used <= k;
    }
    
    double minmaxGasDist(vector<int>& A, int k) {
        double ans = -1;
        
        double l = 0, r = INT_MAX;
        
        while(l <= r) {
            double m = (l + r) / 2.0;
            if(valid(A, k, m)) {
                ans = m;
                r = m - 0.000001;
            }
            else {
                l = m + 0.000001;
            }
        }
        
        return ans;
    }
};