/*
Spiral Matrix
=============

Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 
Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      vector<int> ans;
      int n = matrix.size();
      if(!n) return ans;
      int m = matrix[0].size();
      if(!m) return ans;
      
      int cnt = 0;
      int tne  = n * m;
      int minr = 0;
      int minc = 0;
      int maxr = n - 1;
      int maxc = m - 1;
      
      while(cnt < tne){
        
        // top
        for(int j = minc; j <= maxc && cnt < tne; j++){
          ans.push_back(matrix[minr][j]);
          cnt++;
        }
        minr++;
        
        // right
        for(int i = minr; i <= maxr && cnt < tne; i++){
          ans.push_back(matrix[i][maxc]);
          cnt++;
        }
        maxc--;
        
        // bottom
        for(int j = maxc; j >= minc && cnt < tne; j--){
          ans.push_back(matrix[maxr][j]);
          cnt++;
        }
        maxr--;
        
        // left
        for(int i = maxr; i >= minr && cnt < tne; i--){
          ans.push_back(matrix[i][minc]);
          cnt++;
        }
        minc++;

      }
      
      return ans;
    }
};