/*
                                                #Hacktoberfest2021
You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

Example 1:

Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.


Example 2:

Input: grid = [[1]]
Output: 4


Example 3:

Input: grid = [[1,0]]
Output: 4
 

Constraints:

row == grid.length
col == grid[i].length
1 <= row, col <= 100
grid[i][j] is 0 or 1.
There is exactly one island in grid.

*/

int p = 0;
int vis[101][101];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
class Solution {
public:
    bool isValid(int x,int y,vector<vector<int> >&grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(x<0 || x>=m || y<0 || y>=n || grid[x][y]==0)
            return false;
        
        return true;
    }
    
    void dfs(int x,int y,vector<vector<int> >&grid) {
        vis[x][y] = 1;
        int sq = 4;
        for(int i=0;i<4;i++) {
            if(isValid(x+dx[i],y+dy[i],grid))
            {
                sq--;
                
                if(vis[x+dx[i]][y+dy[i]]==0)
                    dfs(x+dx[i],y+dy[i],grid);
            }
        }
        
        p+=sq;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        p = 0;
        bool got = false;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                vis[i][j] = 0;
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {
                    dfs(i,j,grid);
                    {
                        got = true;
                        break;
                    }
                }
            }
            
            if(got==true)
                break;
        }
        
        return p;
    }
};