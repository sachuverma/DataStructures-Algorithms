/*
Construct Binary Tree from Preorder and Inorder Traversal
=========================================================

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: preorder = [-1], inorder = [-1]
Output: [-1]

Constraints:
1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.
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
  int preI = 0;

  int find(vector<int> &in, int s, int e, int tar)
  {
    for (int i = 0; i <= e; ++i)
    {
      if (in[i] == tar)
        return i;
    }
    return -1;
  }

  TreeNode *build(vector<int> &pre, vector<int> &in, int s, int e)
  {
    if (preI == pre.size() || s > e)
    {
      return NULL;
    }

    int val = pre[preI++];
    TreeNode *root = new TreeNode(val);

    int idx = find(in, s, e, val);
    root->left = build(pre, in, s, idx - 1);
    root->right = build(pre, in, idx + 1, e);
    return root;
  }

  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
  {
    return build(preorder, inorder, 0, inorder.size() - 1);
  }
};
