/*
MAXIMISE DISTANCE TO CLOSEST PERSON
===================================

You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat, and seats[i] = 0 represents that the ith seat is empty (0-indexed).

There is at least one empty seat, and at least one person sitting.
Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized.
Return that maximum distance to the closest person.

Example-1:
Input: seats = [1,0,0,0,1,0,1]
Output: 2
Explanation:
If Alex sits in the second open seat (i.e. seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.

Example-2:
Input: seats = [1,0,0,0]
Output: 3
Explanation:
If Alex sits in the last seat (i.e. seats[3]), the closest person is 3 seats away.
This is the maximum distance possible, so the answer is 3.

Example-3
Input: seats = [0,1]
Output: 1

INTUTION:
Count number of zeros between two adjacent ones and store maximum of half of count in an answer variable.
Take care of edge cases like number of zeros in starting or in end.

TIME COMPLEXITY:O(n)
SPACE COMPLEXITY:O(1)
*/

class Solution
{
public:
  int maxDistToClosest(vector<int> &seats)
  {
    int i = 0;
    int ans = 0;
    int count = 0;
    while (seats[i] == 0)
      i++;

    ans = i;
    int n = seats.size();
    for (; i < n; i++)
    {
      if (seats[i] == 1)
      {
        ans = max(ans, (count + 1) / 2);
        count = 0;
      }
      else
        count++;
    }
    ans = max(ans, count);
    return ans;
  }
};
