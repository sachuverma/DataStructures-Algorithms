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
    if (!root)
      return {};

    int i = 0;
    vector<vector<int>> ans;
    queue<TreeNode *> pending;
    pending.push(root);

    while (pending.size())
    {
      int size = pending.size();
      vector<int> subans;
      for (int i = 0; i < size; ++i)
      {
        auto front = pending.front();
        pending.pop();
        subans.push_back(front->val);
        if (front->left)
          pending.push(front->left);
        if (front->right)
          pending.push(front->right);
      }
      if (i % 2)
        reverse(subans.begin(), subans.end());
      ans.push_back(subans);
      i++;
    }
    return ans;
  }
};
