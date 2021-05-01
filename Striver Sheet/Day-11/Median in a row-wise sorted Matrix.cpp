/*
Median in a row-wise sorted Matrix
==================================

Given a row wise sorted matrix of size RxC where R and C are always odd, find the median of the matrix.

Example 1:
Input:
R = 3, C = 3
M = [[1, 3, 5], 
     [2, 6, 9], 
     [3, 6, 9]]

Output: 5
Explanation:
Sorting matrix elements gives us 
{1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 

Example 2:
Input:
R = 3, C = 1
M = [[1], [2], [3]]

Output: 2
Your Task:  
You don't need to read input or print anything. Your task is to complete the function median() which takes the integers R and C along with the 2D matrix as input parameters and returns the median of the matrix.

Expected Time Complexity: O(32 * R * log(C))
Expected Auxiliary Space: O(1)

Constraints:
1<= R,C <=150
1<= matrix[i][j] <=2000
*/

class Solution
{
public:
  int median(vector<vector<int>> &matrix, int r, int c)
  {
    int mi = INT_MAX, ma = INT_MIN;
    for (int i = 0; i < r; ++i)
    {
      mi = min(mi, matrix[i][0]);
      ma = max(ma, matrix[i][c - 1]);
    }

    int desired = (r * c + 1) / 2;
    while (mi <= ma)
    {
      int mid = ma - (ma - mi) / 2;

      int place = 0;
      for (int i = 0; i < r; ++i)
      {
        place += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
      }

      if (place < desired)
        mi = mid + 1;
      else
        ma = mid - 1;
    }
    return mi;
  }
};
