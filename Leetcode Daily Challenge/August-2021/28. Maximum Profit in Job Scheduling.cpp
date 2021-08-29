/*
Maximum Profit in Job Scheduling
================================

We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.

Example 1:
Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.

Example 2:
Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job. 
Profit obtained 150 = 20 + 70 + 60.

Example 3:
Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
Output: 6

Constraints:
1 <= startTime.length == endTime.length == profit.length <= 5 * 104
1 <= startTime[i] < endTime[i] <= 109
1 <= profit[i] <= 104
*/

class Solution {
public:
    int memo[50001];
    
    int find(vector<vector<int>>& arr, int target, int l, int r){
      while(l < r){
        int m = l+(r-l)/2;
        if(arr[m][0] >= target) 
          r = m;
        else l = m+1;
      }
      if(arr[r][0] >= target) return r;
      return -1;
    }
    
    int dfs(vector<vector<int>>& jobs, int index) {
        if(index >= jobs.size()) return 0;
        
        if(memo[index] != -1) return memo[index];
        
        int ans = 0;
        ans = max(ans, dfs(jobs, index+1));
        
        int next = find(jobs, jobs[index][1], index+1, jobs.size()-1);
        
        ans = max(ans, jobs[index][2] + dfs(jobs, next));
        return memo[index] = ans;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        for(int i = 0; i < startTime.size(); ++i) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        memset(memo, -1, sizeof memo);
        
        sort(jobs.begin(), jobs.end());
        return dfs(jobs, 0);
    }
};