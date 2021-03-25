/*
Advantage Shuffle
=================

Given two arrays A and B of equal size, the advantage of A with respect to B is the number of indices i for which A[i] > B[i].

Return any permutation of A that maximizes its advantage with respect to B.

Example 1:
Input: A = [2,7,11,15], B = [1,10,4,11]
Output: [2,11,7,15]

Example 2:
Input: A = [12,24,8,32], B = [13,25,32,11]
Output: [24,32,8,12]

Note:
1 <= A.length = B.length <= 10000
0 <= A[i] <= 10^9
0 <= B[i] <= 10^9
*/

class Solution
{
public:
  vector<int> advantageCount(vector<int> &A, vector<int> &B)
  {
    vector<vector<int>> b;
    for (int i = 0; i < B.size(); ++i)
      b.push_back({B[i], i});
    sort(b.begin(), b.end(), greater<vector<int>>());
    sort(A.begin(), A.end());
    int i = 0, j = A.size() - 1;
    vector<int> ans(A.size(), -1);

    for (int k = 0; k < b.size(); ++k)
    {
      int pos = b[k][1];

      if (A[j] > b[k][0])
      {
        ans[pos] = A[j];
        j--;
      }
      else
      {
        ans[pos] = A[i];
        i++;
      }
    }

    return ans;
  }
};
