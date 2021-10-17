/*You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

Example 2:
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.

Example 3:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

Constrain:
1 <= prices.length <= 105
0 <= prices[i] <= 105

*/

//----------------------------Approach------------------------
// this problem is quite similar to problem : Best Time to Buy and Sell Stock with Cooldown
// only the way we use sell variable in this question is bit different
// first of all we have three states
// i -> index in which we reach
// cond : cond=0 tell that we haven't bought a stock
// cond : cond=1 tells that we have bought a stock and haven't sold it yet

// sell :  it is the count of how many stock we have sold

// as per the problem we can sell at most 2 stocks
// therefore we will return  if we sell 2 stocks

// Now wherever we will buy stock we will make cond = 1 so that we don't buy a stock before selling the current one (according to question)

// if cond =1 we have two choices
// 1) we can either sell the stock (if we will sell it then we will make sell = 1)
// 2) we can move to (i+1)th index without selling stock

// if cond =0 we have again two choices
// 1) we can buy the stock (if we buy the stock then we have to make cond=1)
// 2) we can move to (i+1)th index without buying stock

// logic
// whenever we buy ith stock and sell jth stock then profit =  price[j]-price[i]
// therefore while buying the stock we are multiplying it with -1

// time complexity and space complexity: O(N*2*3) == O(N);
// n for index , 2 for cond , 3 for sell states respectively


class Solution {
public:
    int len;
    int dp[100005][2][3];
    vector<int>price;
    void init(vector<int>prices){
        price = prices;
        len = price.size();
        for(int i=0;i<len;i++){       // Initializing dp with -1
            dp[i][0][0] = -1;         // we are using dp array to Memoize our recursion so that our time complexity does not reach exponential value
            dp[i][0][1] = -1;
            dp[i][0][2] = -1;
            dp[i][1][0] = -1;
            dp[i][1][1] = -1;
            dp[i][1][2] = -1;
        }
    }
    int solve(int i,int cond,int sell){
        if(i>=len){
            return 0;
        }
        if(dp[i][cond][sell]!=-1)return dp[i][cond][sell];    // if we have visited the same condition then we will return its ans

        if(sell==2){                       // if sell = 2 we will return as we can't sell more than 2 stocks
            return dp[i][cond][sell]=0;
        }
        if(cond==0){                                                        // cond = 0 means we haven't buy any stock yet
            int ans1 = -1*price[i]+solve(i+1,1,sell);                       // if we buy the stock then we will make cond =1 and move to (i+1)th index
            int ans2 = solve(i+1,0,sell);                                   // when we don't buy stock  then we move to (i+1)th index without changing cond
            return dp[i][cond][sell] = max(ans1,ans2);                      // as we have to maximize out profit we will choose maximum out of the two choices
        }
        else{
            int ans1 = solve(i+1,1,sell);                                   // when we don't sell a stock then we move to (i+1)th index without changing sell value
            int ans2 = price[i]+solve(i+1,0,sell+1);                        // when we  sell a stock then we move to (i+1)th index and increment  sell value to sell+1
            return dp[i][cond][sell] = max(ans1,ans2);                      // as we have to maximize out profit we will choose maximum out of the two choices
        }
    }
    int maxProfit(vector<int>& prices) {
        init(prices);  // initializing global variables
        return solve(0,0,0);
    }
};
