// problem statement of this solution can be found here : https://leetcode.com/problems/max-increase-to-keep-city-skyline/

#include<bits/stdc++.h>
/*class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        
        // Naive Approach : Brute Force : O(N*N*N)
        int sum = 0 ;
        
        for(int i = 0 , n = grid.size() ; i < n ; ++i){
            
            for(int j = 0 ; j < n ; ++j){
                
                int maxi = 0, maxj = 0; 
                for(int k = 0 ; k < n ; ++k){
                     maxi = max(maxi , grid[k][j]);       
                }
                
                //cout << maxi << " at " << i << ","<<j << "  ";
                
                for(int k = 0 ; k < n ; ++k){
                    maxj = max(maxj , grid[i][k]) ;
                }
                
                //cout << maxj << " at " << i << ","<<j << "  ";
                
                int value =  ( min(maxi , maxj) - grid[i][j] ) ;
                //int value = maxi <= maxj ? maxi : maxj ;
                //cout << value << " at " << i << ","<<j << "  ";
                //value -= grid[i][j] ;
                //cout << value << " at " << i << ","<<j << "  "; 
                sum += value ; 
                //cout << endl ; 
                
            }
            
        }
        
        return sum ; 
    }
    
  
};*/

// Slight Optimisation : O(N*N) : Calculating max of row and coloumn simultaneously
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size(), res = 0;
        vector<int> rows(n), cols(n);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                rows[i] = max(rows[i], grid[i][j]);
                cols[j] = max(cols[j], grid[i][j]);
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res += min(rows[i], cols[j]) - grid[i][j];
            }
        }
        
        return res;
    }
};
