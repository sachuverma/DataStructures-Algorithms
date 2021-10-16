//https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/

class Solution {
public:

    // Naive Approach : Test Case passes 
    // Learning : intialise extra space in data structure (and loops) to avoid buffer-overflow ( Example in number 9 , 26)
    /*vector<vector<int>> groupThePeople(vector<int>& gs) {
        vector<vector<int> > ans ;
        vector<int> tmp ;
        vector< pair<int , vector<int> > > freq(gs.size() + 1, {0, {}} ) ;
        
        for(int i = 0 ; i < gs.size() ; ++i){
            ++freq[gs[i]].first ;
            freq[gs[i]].second.push_back(i);
        }
        
        
        //debug
        for( auto s : freq){
            cout << s.first << "    " ; 
            for(auto x : s.second){
                cout << x << "," ;
            }
            cout << endl ;
        }
        
        for(int i = 1 ; i < gs.size() + 1; ++i){
            if(freq[i].first > 0){
                int n = i , rem = freq[i].first/i; 
                
                while(rem > 0){
                    n = i ;
                    while(n>0){
                        tmp.push_back( freq[i].second.back());
                        freq[i].second.pop_back();
                        --n ;
                    }
                    
                    /*for(auto s : tmp){
                        cout << "TMP " << s << endl ; 
                    //}
                    
                    ans.push_back(tmp) ;
                    tmp.clear();
                    --rem ;
                }
            }
        }
        return ans ;
    }*/

    // Another Solution found on Discussion Tab
    vector<vector<int>> groupThePeople(vector<int>& gz) {
        vector<vector<int>> res, groups(gz.size() + 1);
        for (auto i = 0; i < gz.size(); ++i) {
            groups[gz[i]].push_back(i);
            if (groups[gz[i]].size() == gz[i]) {
                res.push_back({});
                swap(res.back(), groups[gz[i]]);
            }
            }
        return res;
     }
};
