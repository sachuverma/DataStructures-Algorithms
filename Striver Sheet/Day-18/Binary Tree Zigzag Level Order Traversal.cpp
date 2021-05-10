/*
Binary Tree Zigzag Level Order Traversal
==========================================

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []

Constraints:
The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
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
    vector<vector<int>> ans;
    queue<TreeNode *> q;
    q.push(root);
    bool flag = false;

    while (q.size())
    {
      vector<int> sub;
      for (int i = q.size(); i > 0; --i)
      {
        auto curr = q.front();
        q.pop();
        sub.push_back(curr->val);
        if (curr->left)
          q.push(curr->left);
        if (curr->right)
          q.push(curr->right);
      }
      if (flag)
        reverse(sub.begin(), sub.end());
      ans.push_back(sub);
      flag = !flag;
    }

    return ans;
  }
};
