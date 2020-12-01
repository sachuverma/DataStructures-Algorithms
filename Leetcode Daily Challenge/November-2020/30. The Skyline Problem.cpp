/*
The Skyline Problem
===================

A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo (Figure A), write a program to output the skyline formed by these buildings collectively (Figure B).

Buildings Skyline Contour
The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .

The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.

For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].

Notes:
The number of buildings in any input list is guaranteed to be in the range [0, 10000].
The input list is already sorted in ascending order by the left x position Li.
The output list must be sorted by the x position.
There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...[2 3], [4 5], [12 7], ...]
*/

#define pii pair<int, int>
class Solution
{
public:
  void vector_push(vector<vector<int>> &out, int point, int height)
  {
    vector<int> temp;
    temp.push_back(point);
    temp.push_back(height);
    out.push_back(temp);
  }
  vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
  {
    vector<vector<int>> out;
    int i = 0;
    int curr_x = 0;
    int curr_height = -1;
    int prev_height = 0;
    int n = buildings.size();
    priority_queue<pii> pq;

    while (i < n || !pq.empty())
    {

      curr_x = pq.empty() ? buildings[i][0] : pq.top().second;

      if (i >= n || buildings[i][0] > curr_x)
      {
        while (!pq.empty() && (pq.top().second <= curr_x))
          pq.pop();
      }
      else
      {
        curr_x = buildings[i][0];
        while (i < n && buildings[i][0] == curr_x)
        {
          pq.push({buildings[i][2], buildings[i][1]});
          i++;
        }
      }
      curr_height = pq.empty() ? 0 : pq.top().first; // outut the top one
      if (prev_height != curr_height)
        vector_push(out, curr_x, curr_height), prev_height = curr_height;
    }
    return out;
  }
};
