/*
Buddy Strings
=============

Given two strings A and B of lowercase letters, return true if you can swap two letters in A so the result is equal to B, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at A[i] and A[j]. For example, swapping at indices 0 and 2 in "abcd" results in "cbad".


Example 1:
Input: A = "ab", B = "ba"
Output: true
Explanation: You can swap A[0] = 'a' and A[1] = 'b' to get "ba", which is equal to B.

Example 2:
Input: A = "ab", B = "ab"
Output: false
Explanation: The only letters you can swap are A[0] = 'a' and A[1] = 'b', which results in "ba" != B.

Example 3:
Input: A = "aa", B = "aa"
Output: true
Explanation: You can swap A[0] = 'a' and A[1] = 'a' to get "aa", which is equal to B.

Example 4:
Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true

Example 5:
Input: A = "", B = "aa"
Output: false


Constraints:
0 <= A.length <= 20000
0 <= B.length <= 20000
A and B consist of lowercase letters.

*/

class Solution {
public:
  bool buddyStrings(string A, string B) {
    if(A.size() != B.size()) return false;

    vector<int> same(26,0);
    for(auto i:A) same[i-'a']++;

    vector<int> indices; 
    int f = 0;

    for(int i=0; i<A.size(); ++i){
      if(A[i] == B[i]) continue;
      else { 
        indices.push_back(i);
        f = 1;
      }
    }

    int find=0;
    for(auto i:same) if(i>=2){ find=1; break;}
    if(f==0 && find==1) return true;

    if(find==0 && A==B) return false;
    if(f==1 && indices.size() != 2) return false;

    if(indices.size()==2 && A[indices[0]] != B[indices[1]]) return false;
    if(indices.size()==2 && A[indices[1]] != B[indices[0]]) return false;
    return true;
  }
};
