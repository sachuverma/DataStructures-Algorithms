/*
Coin Change
===========

You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:
Input: coins = [2], amount = 3
Output: -1

Example 3:
Input: coins = [1], amount = 0
Output: 0

Example 4:
Input: coins = [1], amount = 1
Output: 1

Example 5:
Input: coins = [1], amount = 2
Output: 2

Constraints:
1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      vector<long long> dp(amount+1, INT_MAX);
      dp[0] = 0;
      
      for(int i=1; i<=amount; ++i){
        for(auto &coin: coins){
          if(coin <= i) dp[i] = min(dp[i], dp[i-coin]+1);
        }
      }
      
      return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

