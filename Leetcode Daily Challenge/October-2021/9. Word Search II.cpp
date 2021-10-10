/*
Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 
Example 1:

Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]


Example 2:

Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 12
board[i][j] is a lowercase English letter.
1 <= words.length <= 3 * 104
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
All the strings of words are unique.
*/


set<string> res;

class Solution {
    struct TrieNode {
        bool end;
        vector<TrieNode*> c;
        
        TrieNode() {
            end = false;
        c.resize(26,NULL);
        }
    };
    
public:
    TrieNode* build(vector<string> &w) {
        int n = w.size();
        TrieNode* root = new TrieNode();
        
        for(int i=0;i<n;i++) {
            TrieNode* curr = root;
            string word= w[i];
            
            for(int j=0;j<word.length();j++) {
                if(curr->c[word[j]-'a']==NULL)
            {
                    TrieNode* t = new TrieNode();
                curr->c[word[j]-'a'] = t;
            }
            
            curr = curr->c[word[j]-'a'];
            }
            
            curr->end = true;
        }
        
        return root;
    }
    
    void dfs(int x,int y,vector<vector<char> >&b,vector<string> &w,TrieNode* root,string ans) {
        if(x<0 || x>=b.size() || y<0 || y>=b[0].size() || b[x][y]==' ')
            return;
        
        if(root->c[b[x][y]-'a']!=NULL) {
            ans+=b[x][y];
            root = root->c[b[x][y]-'a'];
            
            if(root->end)
                res.insert(ans);
            
            char ch = b[x][y];
            b[x][y] = ' ';
            
            dfs(x+1,y,b,w,root,ans);
            dfs(x,y+1,b,w,root,ans);
            dfs(x-1,y,b,w,root,ans);
            dfs(x,y-1,b,w,root,ans);
            
            b[x][y] = ch;
        }
    }
    
    vector<string> findWords(vector<vector<char>>& b, vector<string>& w) {
        TrieNode* root = build(w);
        res.clear();
        
        for(int i=0;i<b.size();i++) {
            for(int j=0;j<b[0].size();j++) {
                dfs(i,j,b,w,root,"");
            }
        }
        
        vector<string> v;
        
        for(auto u:res)
            v.push_back(u);
        
        return v;
    }
};