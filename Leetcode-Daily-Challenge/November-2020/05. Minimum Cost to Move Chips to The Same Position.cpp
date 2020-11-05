/*
Minimum Cost to Move Chips to The Same Position
===============================================

We have n chips, where the position of the ith chip is position[i].

We need to move all the chips to the same position. In one step, we can change the position of the ith chip from position[i] to:

position[i] + 2 or position[i] - 2 with cost = 0.
position[i] + 1 or position[i] - 1 with cost = 1.
Return the minimum cost needed to move all the chips to the same position.


Example 1:
Input: position = [1,2,3]
Output: 1
Explanation: First step: Move the chip at position 3 to position 1 with cost = 0.
Second step: Move the chip at position 2 to position 1 with cost = 1.
Total cost is 1.

Example 2:
Input: position = [2,2,2,3,3]
Output: 2
Explanation: We can move the two chips at poistion 3 to position 2. Each move has cost = 1. The total cost = 2.

Example 3:
Input: position = [1,1000000000]
Output: 1


Constraints:
1 <= position.length <= 100
1 <= position[i] <= 10^9

Hint #1  
The first move keeps the parity of the element as it is.

Hint #2  
The second move changes the parity of the element.

Hint #3  
Since the first move is free, if all the numbers have the same parity, the answer would be zero.

Hint #4  
Find the minimum cost to make all the numbers have the same parity.
*/

class Solution
{
public:
  int minCostToMoveChips(vector<int> &position)
  {
    int even = 0, odd = 0;
    for (auto i : position)
    {
      if (i % 2 == 0)
        even++;
      else
        odd++;
    }

    return min(even, odd);
  }
};
