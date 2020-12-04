/*
Binary Tree Zigzag Level Order Traversal
========================================

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
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
  vector<vector<int>> zigzagLevelOrder(TreeNode *root)
  {
    vector<vector<int>> ans;
    if (!root)
      return ans;
    queue<TreeNode *> pending;
    pending.push(root);
    bool zigzag = false;

    while (pending.size())
    {
      int size = pending.size();
      vector<int> subans;
      for (int i = 0; i < size; ++i)
      {
        auto node = pending.front();
        pending.pop();
        subans.push_back(node->val);
        if (node->left)
          pending.push(node->left);
        if (node->right)
          pending.push(node->right);
      }
      if (zigzag)
        reverse(subans.begin(), subans.end());
      zigzag = !zigzag;
      ans.push_back(subans);
    }
    return ans;
  }
};
