/*
Largest Plus Sign
=================

You are given an integer n. You have an n x n binary grid grid with all values initially 1's except for some indices given in the array mines. The ith element of the array mines is defined as mines[i] = [xi, yi] where grid[xi][yi] == 0.

Return the order of the largest axis-aligned plus sign of 1's contained in grid. If there is none, return 0.

An axis-aligned plus sign of 1's of order k has some center grid[r][c] == 1 along with four arms of length k - 1 going up, down, left, and right, and made of 1's. Note that there could be 0's or 1's beyond the arms of the plus sign, only the relevant area of the plus sign is checked for 1's.

Example 1:
Input: n = 5, mines = [[4,2]]
Output: 2
Explanation: In the above grid, the largest plus sign can only be of order 2. One of them is shown.

Example 2:
Input: n = 1, mines = [[0,0]]
Output: 0
Explanation: There is no plus sign, so return 0.
 
Constraints:
1 <= n <= 500
1 <= mines.length <= 5000
0 <= xi, yi < n
All the pairs (xi, yi) are unique.

Hint #1  
For each direction such as "left", find left[r][c] = the number of 1s you will see before a zero starting at r, c and walking left. You can find this in N^2 time with a dp. The largest plus sign at r, c is just the minimum of left[r][c], up[r][c] etc.
*/

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int>(n, 1));
        
        for(auto& mine: mines) {
            grid[mine[0]][mine[1]] = 0;
        }
        
        // i,j => { left, right, up, down }
        vector<vector<vector<int>>> DP(n, vector<vector<int>> (n, vector<int>(4, 1)));
        
        // left prefix count
        for(int i = 0; i < n; ++i) {
            for(int j = 1; j < n; ++j) {
                DP[i][j][0] = 1 + DP[i][j-1][0];
                if(grid[i][j-1] == 0) DP[i][j][0] = 1;
            }
        }
        
        // right prefix
        for(int i = 0; i < n; ++i) {
            for(int j = n-2; j >= 0; --j) {
                DP[i][j][1] = 1 + DP[i][j+1][1];
                if(grid[i][j+1] == 0) DP[i][j][1] = 1;
            }
        }
        
        // up prefix count
        for(int j = 0; j < n; ++j) {
            for(int i = 1; i < n; ++i) {
                DP[i][j][2] = 1 + DP[i-1][j][2];
                if(grid[i-1][j] == 0) DP[i][j][2] = 1;
            }
        }
        
        // down prefix
        for(int j = 0; j < n; ++j) {
            for(int i = n-2; i >= 0; --i) {
                DP[i][j][3] = 1 + DP[i+1][j][3];
                if(grid[i+1][j] == 0) DP[i][j][3] = 1;
            }
        }
        
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 1){
                    int sub_ans = min({ DP[i][j][0], DP[i][j][1], DP[i][j][2], DP[i][j][3] });
                    // cout << i << "," << j << "," << sub_ans << endl;
                    ans = max(ans, sub_ans);
                }
            }
        }
        
        return ans;
    }
};
