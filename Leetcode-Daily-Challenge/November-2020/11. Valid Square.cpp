/*
Valid Square
============

Given the coordinates of four points in 2D space, return whether the four points could construct a square.

The coordinate (x,y) of a point is represented by an integer array with two integers.

Example:
Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: True


Note:
All the input integers are in the range [-10000, 10000].
A valid square has four equal sides with positive length and four equal angles (90-degree angles).
Input points have no order.
*/

class Solution
{
  bool cacl(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
  {
    float dist1 = pow((p1[0] - p2[0]), 2) + pow((p1[1] - p2[1]), 2);
    float dist2 = pow((p1[0] - p3[0]), 2) + pow((p1[1] - p3[1]), 2);
    float dist3 = pow((p1[0] - p4[0]), 2) + pow((p1[1] - p4[1]), 2);

    if (dist1 && dist2 && dist3 && dist1 == dist2 && dist1 + dist2 == dist3)
      return true;
    if (dist1 && dist2 && dist3 && dist1 == dist3 && dist1 + dist3 == dist2)
      return true;
    if (dist1 && dist2 && dist3 && dist3 == dist2 && dist3 + dist2 == dist1)
      return true;
    return false;
  }

public:
  bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
  {
    return cacl(p1, p2, p3, p4) && cacl(p2, p3, p4, p1) && cacl(p3, p4, p1, p2) && cacl(p4, p1, p2, p3);
  }
};
