class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        stack<int>S;
        for(int i=0;i<nums2.size();i++){
            if(S.empty()) S.push(nums2[i]);
            else{
                if(S.top()>nums2[i]) S.push(nums2[i]);
                else{
                    while(!S.empty()){
                        if(S.top()<=nums2[i]){
                            mp[S.top()]=nums2[i];
                            S.pop();
                        }
                        else break;
                    }
                    S.push(nums2[i]);
                }
            }
        }
        vector<int>ans;
        for(int x:nums1){
            if(mp[x]>0) ans.push_back(mp[x]);
            else ans.push_back(-1);
        }
        return ans;
    }
};
