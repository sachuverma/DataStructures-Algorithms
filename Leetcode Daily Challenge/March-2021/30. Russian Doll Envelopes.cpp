/*
Russian Doll Envelopes
======================

You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.
Return the maximum number of envelopes can you Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.

Example 1:
Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

Example 2:
Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1

Constraints:
1 <= envelopes.length <= 5000
envelopes[i].length == 2
1 <= wi, hi <= 104
*/

class Solution
{
  bool static isSmall(vector<int> &a, vector<int> &b)
  {
    return a[0] < b[0] && a[1] < b[1];
  }

public:
  int maxEnvelopes(vector<vector<int>> &env)
  {
    int ans = 1;
    int n = env.size();
    vector<int> dp(n, 1);
    sort(env.begin(), env.end());

    for (int i = 1; i < n; ++i)
    {
      int prev = 0;
      for (int j = 0; j < i; ++j)
      {
        if (isSmall(env[j], env[i]))
          prev = max(prev, dp[j]);
      }
      dp[i] = prev + 1;
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};
