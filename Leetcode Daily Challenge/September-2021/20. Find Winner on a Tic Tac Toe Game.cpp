/*
Find Winner on a Tic Tac Toe Game
=================================

Tic-tac-toe is played by two players A and B on a 3 x 3 grid. The rules of Tic-Tac-Toe are:

Players take turns placing characters into empty squares ' '.
The first player A always places 'X' characters, while the second player B always places 'O' characters.
'X' and 'O' characters are always placed into empty squares, never on filled ones.
The game ends when there are three of the same (non-empty) character filling any row, column, or diagonal.
The game also ends if all squares are non-empty.
No more moves can be played if the game is over.
Given a 2D integer array moves where moves[i] = [rowi, coli] indicates that the ith move will be played on grid[rowi][coli]. return the winner of the game if it exists (A or B). In case the game ends in a draw return "Draw". If there are still movements to play return "Pending".

You can assume that moves is valid (i.e., it follows the rules of Tic-Tac-Toe), the grid is initially empty, and A will play first.

Example 1:
Input: moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
Output: "A"
Explanation: A wins, they always play first.

Example 2:
Input: moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
Output: "B"
Explanation: B wins.

Example 3:
Input: moves = [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]
Output: "Draw"
Explanation: The game ends in a draw since there are no moves to make.

Example 4:
Input: moves = [[0,0],[1,1]]
Output: "Pending"
Explanation: The game has not finished yet.
 
Constraints:
1 <= moves.length <= 9
moves[i].length == 2
0 <= rowi, coli <= 2
There are no repeated elements on moves.
moves follow the rules of tic tac toe.
*/

class Solution {
public:
    char check(vector<vector<char>>&board){
      for(auto &row: board){
        auto ch = row[0];
        if(ch == ' ') continue;
        int flag = 0;
        for(int i=1; i<row.size(); ++i){
          if(row[i] != ch){ 
            flag = 1;
            break;
          }
        }
        if(!flag) return ch;
      }
      
      for(int i=0; i<3; ++i){
        auto ch = board[0][i];
        int flag = 0;
        for(int j=1; j<3; ++j){
          if(board[j][i] != ch){
            flag = 1;
            break;
          }
        }
        if(!flag) return ch;
      }
      
      char ch1 = board[0][0], ch2 = board[0][2];
      
      
      if(ch1 != ' '){
        int flag = 0;
        for(int i=1; i<3; ++i){
          if(board[i][i] != ch1){
            flag = 1;
            break;
          }
        }
        
      if(!flag) return ch1;
      }
      
      if(ch2 != ' '){
        int flag = 0;
        for(int i=1; i<3; ++i){
          if(board[i][2-i] != ch2){
            flag = 1;
            break;
          }
        }
        
      if(!flag) return ch2;
      }
      
      
      return '-';
    }
  
    string tictactoe(vector<vector<int>>& moves) {
      vector<vector<char>> board(3,vector<char>(3,' '));
      char turn = 'X';
      string ans = "Draw";
      int count = 0;
      
      for(auto &i: moves){
        count++;
        int x = i[0], y = i[1];
        
        if(turn == 'X'){
          board[x][y] = 'X';
          turn = 'O';
        } else {
          board[x][y] = 'O';
          turn = 'X';
        }
        
        if(check(board) == 'X') return "A";
        else if(check(board) == 'O') return "B";
      }
      
      return count < 9 ? "Pending" : "Draw";
      
    }
};

