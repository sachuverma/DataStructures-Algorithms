/*
Binary Tree Right Side View
===========================

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:
Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
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
  vector<int> rightSideView(TreeNode *root)
  {
    if (!root)
      return {};
    vector<int> ans;
    queue<TreeNode *> pending;
    pending.push(root);
    while (pending.size())
    {
      int size = pending.size();
      for (int i = 0; i < size; ++i)
      {
        auto curr = pending.front();
        pending.pop();
        if (curr->left)
          pending.push(curr->left);
        if (curr->right)
          pending.push(curr->right);
        if (i == size - 1)
          ans.push_back(curr->val);
      }
    }

    return ans;
  }
};
