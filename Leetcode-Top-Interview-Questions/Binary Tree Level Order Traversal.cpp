/*
Binary Tree Level Order Traversal
=================================

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
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
  vector<vector<int>> levelOrder(TreeNode *root)
  {
    if (!root)
      return {};

    vector<vector<int>> ans;
    queue<TreeNode *> pending;
    pending.push(root);

    while (pending.size())
    {
      vector<int> subans;
      int size = pending.size();
      for (int i = 0; i < size; ++i)
      {
        TreeNode *fr = pending.front();
        pending.pop();
        subans.push_back(fr->val);
        if (fr->left)
          pending.push(fr->left);
        if (fr->right)
          pending.push(fr->right);
      }
      ans.push_back(subans);
    }

    return ans;
  }
};
