
class Solution
{
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    if (matrix.size() == 0)
      return false;
    if (matrix[0].size() == 0)
      return false;

    int n = matrix.size(), m = matrix[0].size();
    int r = 0, c = m - 1;
    while (r < n && c >= 0)
    {
      if (matrix[r][c] == target)
        return true;
      else if (matrix[r][c] > target)
        c--;
      else
        r++;
    }
    return false;
  }
};
