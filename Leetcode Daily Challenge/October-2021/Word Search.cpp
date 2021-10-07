/*
                                                #Hacktoberfest2021
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true


Example 2:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true


Example 3:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
*/

int vis[7][7];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
bool found = false;

class Solution {
public:
    bool isValid(int x,int y,char c,vector<vector<char>> &board) {
        if(x<0 || x>=board.size() || y<0 || y>=board[0].size())
            return false;
        
        if(vis[x][y]==1 || board[x][y]!=c)
            return false;
        
        return true;
    }
    
    void dfs(int x,int y,int k,string word,vector<vector<char>> &board) {
        if(k==word.length()-1)
        {
            found = true;
            return;
        }
        vis[x][y]=1;
        
        for(int i=0;i<4;i++) {
            if(isValid(x+dx[i],y+dy[i],word[k+1],board))
                dfs(x+dx[i],y+dy[i],k+1,word,board);
        }
        
        vis[x][y] = 0;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        char f = word[0];
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                vis[i][j] = 0;
            }
        }
        
       found = false;
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j]==f && found==false) {
                    dfs(i,j,0,word,board);
                    
                    if(found==true)
                        return true;
                }
            }
        }
        
        return false;
    }
};