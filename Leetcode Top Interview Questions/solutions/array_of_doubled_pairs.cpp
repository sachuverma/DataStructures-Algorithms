//  Link to the problem:
//  https://leetcode.com/problems/array-of-doubled-pairs/

// Problem Name=> Array of Doubled Pairs
// Problem Type=> Medium

// Solution:

class Solution {
public:
    static bool compare(int a,int b){
        return abs(a)<abs(b);
    }
    bool canReorderDoubled(vector<int>& A) {
        sort(A.begin(),A.end(),compare);
        unordered_map<int,int> m;
        for(int i=0;i<A.size();i++)m[A[i]]++;
        for(int i=0;i<A.size();i++){
            if(m[A[i]]==0) //If element has been already used by smaller element
                continue;
            if(m[2*A[i]]==0) //If I am unable to get its pair, I will return false
                return false;
            m[2*A[i]]--,m[A[i]]--; //Subtracting frequency of this pair of elements from map
        }
        return true;
    }
};