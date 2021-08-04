/*
Path Sum II
===========

Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where each path's sum equals targetSum.

A leaf is a node with no children.

Example 1:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]

Example 2:
Input: root = [1,2,3], targetSum = 5
Output: []

Example 3:
Input: root = [1,2], targetSum = 0
Output: []

Constraints:
The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000
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

class Solution
{
public:
    void dfs(TreeNode *root, vector<vector<int>> &ans, vector<int> &path, int target, int curr)
    {
        if (!root->left && !root->right)
        {
            path.push_back(root->val);
            if (curr + root->val == target)
                ans.push_back(path);
            path.pop_back();
            return;
        }

        path.push_back(root->val);
        if (root->left)
            dfs(root->left, ans, path, target, curr + root->val);
        if (root->right)
            dfs(root->right, ans, path, target, curr + root->val);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return {};

        vector<vector<int>> ans;
        vector<int> curr;
        dfs(root, ans, curr, targetSum, 0);
        return ans;
    }
};