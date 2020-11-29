/*
Best Time to Buy and Sell Stock IV
==================================

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Notice that you may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



Example 1:
Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

Example 2:
Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.


Constraints:
0 <= k <= 109
0 <= prices.length <= 104
0 <= prices[i] <= 1000

*/

class Solution
{
public:
  int find(vector<int> &prices, int ind, bool buy, int c, int k, vector<vector<vector<int>>> &memo)
  {
    if (ind >= prices.size() || c >= k)
      return 0; //counter
    else if (memo[ind][buy][c] != -1)
      return memo[ind][buy][c];

    if (buy)
    {
      return memo[ind][buy][c] = max(-prices[ind] + find(prices, ind + 1, !buy, c, k, memo), find(prices, ind + 1, buy, c, k, memo));
    }
    else
    {
      return memo[ind][buy][c] = max(prices[ind] + find(prices, ind + 1, !buy, c + 1, k, memo), find(prices, ind + 1, buy, c, k, memo));
    }
  }

  int maxProfit(int k, vector<int> &prices)
  {

    if (2 * k > prices.size())
    {
      int res = 0;
      for (int i = 1; i < prices.size(); i++)
      {
        res += max(0, prices[i] - prices[i - 1]);
      }
      return res;
    }

    vector<vector<vector<int>>> memo(prices.size() + 1, vector<vector<int>>(2, vector<int>(k + 1, -1)));
    return find(prices, 0, 1, 0, k, memo);
  }
};
