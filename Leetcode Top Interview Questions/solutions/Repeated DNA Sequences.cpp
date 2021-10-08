class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map <string, int> freq;
        vector<string> out;
        
        if(s.size()<11){
            return out;
        }
        
        for(int i=0; i<s.size()-9; i++){
            string temp = s.substr(i, 1+9);
            freq[temp]++;
        }
        
        for(auto x : freq){
            if(x.second>1){
                out.push_back(x.first);
            }
        }
        
        return out;
    }
};
