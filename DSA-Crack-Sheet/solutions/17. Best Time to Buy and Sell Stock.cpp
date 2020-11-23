class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int profit = 0;
    int sp = INT_MIN;

    for (int i = prices.size() - 1; i >= 0; --i)
    {
      sp = max(sp, prices[i]);
      profit = max(profit, sp - prices[i]);
    }

    return profit;
  }
};
