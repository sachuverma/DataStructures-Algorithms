/*
Fractional Knapsack
===================

Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item. 

Example 1:
Input:
N = 3, W = 50
values[] = {60,100,120}
weight[] = {10,20,30}
Output:
240.00
Explanation:Total maximum value of item
we can have is 240.00 from the given
capacity of sack. 

Example 2:
Input:
N = 2, W = 50
values[] = {60,100}
weight[] = {10,20}
Output:
160.00
Explanation:
Total maximum value of item
we can have is 160.00 from the given
capacity of sack.

Your Task :
Complete the function fractionalKnapsack() that receives maximum capacity , array of structure/class and size n and returns a double value representing the maximum value in knapsack.
Note: The details of structure/class is defined in the comments above the given function.

Expected Time Complexity : O(NlogN)
Expected Auxilliary Space: O(1)

Constraints:
1 <= N <= 105
1 <= W <= 105
*/

struct Compare
{
  bool operator()(Item &a, Item &b)
  {
    double A = a.value / (1.0 * a.weight), B = b.value / (1.0 * b.weight);
    return A < B;
  }
};

double fractionalKnapsack(int W, Item arr[], int n)
{
  priority_queue<Item, vector<Item>, Compare> pq;
  for (int i = 0; i < n; ++i)
    pq.push(arr[i]);

  double ans = 0;
  double weight = 0;

  while (weight < W && pq.size())
  {
    auto item = pq.top();
    pq.pop();
    if (weight + item.weight <= W)
    {
      weight += item.weight;
      ans += item.value;
    }
    else
    {
      double part = (W - weight) / (1.0 * item.weight);
      weight = W;
      ans += part * item.value;
    }
  }

  return ans;
}