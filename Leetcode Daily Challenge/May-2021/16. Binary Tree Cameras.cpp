/*
Binary Tree Cameras
===================

Given a binary tree, we install cameras on the nodes of the tree. 

Each camera at a node can monitor its parent, itself, and its immediate children.

Calculate the minimum number of cameras needed to monitor all nodes of the tree.

Example 1:
Input: [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.

Example 2:
Input: [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.

Note:
The number of nodes in the given tree will be in the range [1, 1000].
Every node has value 0.
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

// dp(node, place, parentHas)
// ans = min of dp(root,0,0) and dp(root,1,0)

class Solution
{
public:
  int dfs(TreeNode *root, int currHas, int parentHas, map<pair<TreeNode *, pair<int, int>>, int> &memo)
  {
    if (!root)
    {
      if (currHas)
        return 1e6;
      return 0;
    }

    if (!root->left && !root->right)
    {
      if (currHas)
        return 1;
      else
      {
        if (parentHas)
          return 0;
        else
          return 1e6;
      }
    }

    if (memo.find({root, {currHas, parentHas}}) != memo.end())
      return memo[{root, {currHas, parentHas}}];

    int ans = 0;

    if (currHas)
      ans = 1 + min(dfs(root->left, 0, 1, memo), dfs(root->left, 1, 1, memo)) + min(dfs(root->right, 0, 1, memo), dfs(root->right, 1, 1, memo));

    else
    {

      if (parentHas)
        ans = min(dfs(root->left, 0, 0, memo), dfs(root->left, 1, 0, memo)) + min(dfs(root->right, 0, 0, memo), dfs(root->right, 1, 0, memo));
      else
      {
        int op1 = dfs(root->left, 1, 0, memo) + min(dfs(root->right, 0, 0, memo), dfs(root->right, 1, 0, memo));
        int op2 = dfs(root->right, 1, 0, memo) + min(dfs(root->left, 0, 0, memo), dfs(root->left, 1, 0, memo));
        ans = min(op1, op2);
      }
    }

    return memo[{root, {currHas, parentHas}}] = ans;
  }

  int minCameraCover(TreeNode *root)
  {
    map<pair<TreeNode *, pair<int, int>>, int> memo;
    return min(dfs(root, 0, 0, memo), dfs(root, 1, 0, memo));
  }
};
