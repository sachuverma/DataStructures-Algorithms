// SUPER EGG DROP
// ===============

// You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.

// You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.

// Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

// Return the minimum number of moves that you need to determine with certainty what the value of f is.

 

// Example 1:

// Input: k = 1, n = 2
// Output: 2
// Explanation: 
// Drop the egg from floor 1. If it breaks, we know that f = 0.
// Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
// If it does not break, then we know f = 2.
// Hence, we need at minimum 2 moves to determine with certainty what the value of f is.
// Example 2:

// Input: k = 2, n = 6
// Output: 3
// Example 3:

// Input: k = 3, n = 14
// Output: 4
 

// Constraints:

// 1 <= k <= 100
// 1 <= n <= 104

class Solution {
public:
  int superEggDrop(int k, int n) {
        
    int dp[n+1][k+1];
        
    for(int j=0; j<k+1; j++){
      dp[0][j] = 0;
      dp[1][j] = 1;
    }
        
    for(int i=0; i<n+1; i++){
      dp[i][0] = 0;
      dp[i][1] = i;
    }
        
    for(int j=2; j<k+1; j++){
      for(int i=2; i<n+1; i++){
                
        int ans = INT_MAX;
        int low = 1;
        int high = i;
        while(high >= low){
          int mid = (high+low)/2;
          int up = dp[i-mid][j];
        	int down = dp[mid-1][j-1];
          int temp = max(up, down)  +1;
          ans = min(ans, temp);
                    
          if(up > down)
        	  low = mid+1;
          else 
            high = mid-1;
      	}
      	dp[i][j] = ans;
      }
  	}
        
    return dp[n][k];
  }
};