/*You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like
(i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:
Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

Example 2:
Input: prices = [1]
Output: 0

Constraint :
1 <= prices.length <= 5000
0 <= prices[i] <= 1000
*/

class Solution {
public:
    int len;
    int dp[5003][2][2];
    vector<int>price;
    void init(vector<int>prices){
        price = prices;
        len = price.size();
        for(int i=0;i<len;i++){  // initalizing the dp with -1
            dp[i][0][0] = -1;
            dp[i][0][1] = -1;
            dp[i][1][0] = -1;
            dp[i][1][1] = -1;
        }
    }
    // first of all we have three states
    // i -> index in which we reach
    // cond : cond=0 tell that we haven't bought a stock
    // cond : cond=1 tells that we have bought a stock and haven't sold it yet

    // sell : sell=1 tells that whether we have sold (i-1)th stock
    // sell : sell=0 tells that we have not sold (i-1)th stock

    // before buying any stocks we need to check if we have just sold the previous stock or not
    // if we have sold (i-1)th sock then we cant buy the ith stock
    // whenever we will sell ith stock we will make sell = 1
    // if sell = 1 the at ith index then we cant buy or sell therefore we will move to (i+1)th index and make sell = 0

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

    // time complexity and space complexity: O(N*2*2) == O(N);
    // n for index , 2 for cond , 2 for sell states respectively

    int solve(int i,int cond,int sell){
        if(i>=len){
            return 0;
        }
        if(dp[i][cond][sell]!=-1)return dp[i][cond][sell];     // if we have encounter the same condition then we will return its ans
        if(sell==1){
            return dp[i][cond][sell] = solve(i+1,cond,0);     // moving to (i+1)th index and making sell=0
        }
        if(cond==0){
            int ans1 = -1*price[i]+solve(i+1,1,0);         // buying the stock and moving to (i+1)th by making cond =1
            int ans2 = solve(i+1,0,0);                    // not buying a stock and moving to (i+1)th stock
            return dp[i][cond][sell] = max(ans1,ans2);   // we will taken max of both condition as we have to increase our profits
        }
        else{
            int ans1 = solve(i+1,1,0);                   // not selling ith stock and moving to (i+1)th
            int ans2 = price[i]+solve(i+1,0,1);          // selling the ith stock and moving to (i+1)th stock by making sell=1 and cond = 0
            return dp[i][cond][sell] = max(ans1,ans2);  // we will taken max of both condition as we have to increase our profits
        }
    }
    int maxProfit(vector<int>& prices) {
        init(prices);                              // initializing our global variables
        return solve(0,0,0);
    }
};
