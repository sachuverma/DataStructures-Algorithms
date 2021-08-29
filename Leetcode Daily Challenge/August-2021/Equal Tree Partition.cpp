/*
Equal Tree Partition
====================

Given the root of a binary tree, return true if you can partition the tree into two trees with equal sums of values after removing exactly one edge on the original tree.

Example 1:
Input: root = [5,10,10,null,null,2,3]
Output: true

Example 2:
Input: root = [1,2,10,null,null,2,20]
Output: false
Explanation: You cannot split the tree into two trees with equal sums after removing exactly one edge on the tree.

Constraints:
The number of nodes in the tree is in the range [1, 104].
-105 <= Node.val <= 105
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int dfs1(TreeNode* root) {
        if(!root) return 0;
        return root->val + dfs1(root->left) + dfs1(root->right);
    }
    
    int dfs2(TreeNode* root, int& halfSum, bool& ans) {
        int left = 0, right = 0;
        if(root->left) {
            left = dfs2(root->left, halfSum, ans);
            if(left == halfSum) {
                ans = true;
                return 0;
            }
        }
        
        if(root->right) {
            right = dfs2(root->right, halfSum, ans);
            if(right == halfSum) {
                ans = true;
                return 0;
            }
        }
        
        return root->val + left + right;
    }
    
    bool checkEqualTree(TreeNode* root) {
        int fullSum = dfs1(root);
        
        if(fullSum % 2 != 0) return false;
        int halfSum = fullSum / 2;
        
        bool ans = false;
        dfs2(root, halfSum, ans);
        
        return ans;
    }
};
