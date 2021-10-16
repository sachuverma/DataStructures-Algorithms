//LeetCode Problem of Arrays ( Medium ) : https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/submissions/

class Solution {
public:
    //Brute Force Approach : Accepted as constraints for N was small 
    /*vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n) ;
        
        for(int i = 0 ; i < n ; ++i){
            int sum = 0 ;
            for(int j = 0 ; j < n ; ++j){
                if(boxes[j] == '1')
                    sum += abs(j - i);
            }
            ans[i] = sum ;
        }
        
        return ans ; 
    }*/
    
    //Optimised using Prefix and Postfix Sum
  /*  
    vector<int> minOperations(string boxes){
        int n = boxes.size();
        vector<int> ans(n) ; 
        
        vector<pair<int, int> > pre(n, {0, 0}) , post(n, {0 , 0}) ;
        int value ; 
        for(int i = 1 ; i < n ; ++i){
            if(boxes[i-1] == '1')
                value = 1 ;
            else
                value = 0 ;
            
            pre[i].first = pre[i-1].first + pre[i-1].second + value ;//(int)boxes[i-1] ;
            pre[i].second = pre[i-1].second + value ;  
        }
        
        for(int i = n-2 ; i >= 0 ; --i){
            if(boxes[i+1] == '1')
                value = 1 ;
            else
                value = 0 ;
            post[i].first = post[i+1].first + post[i+1].second + value ;//(int)boxes[i+1] ;
            post[i].second = post[i+1].second + value ; 
        }
        
        //Debug
     /*   
        for(int i = 0 ; i < n ; ++i){
            cout << pre[i].first << "," << pre[i].second << "   ";
        }
        cout << endl ; 
        
        for(int i = 0 ; i < n ; ++i){
            cout << post[i].first << "," << post[i].second << "     " ;
        }
        cout << endl ; 
      
    
        for(int i = 0 ; i < n ; ++i){
            ans[i] = pre[i].first + post[i].first ;
        }
        
        
        return ans ;
    }
   */ 
    
    //Even Faster : Found in Discussions Tab
    
    vector<int> minOperations(string boxes) {
    vector<int> res(boxes.length()); 
    for (int i = 0, ops = 0, cnt = 0; i < boxes.length(); ++i) {
       res[i] += ops;
       cnt += boxes[i] == '1' ? 1 : 0;
       ops += cnt;
    }
    for (int i = boxes.length() - 1, ops = 0, cnt = 0; i >= 0; --i) {
        res[i] += ops;
        cnt += boxes[i] == '1' ? 1 : 0;
        ops += cnt;
        }
        return res;
    }
};
