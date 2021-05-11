/*
Construct Binary Tree from Preorder and Inorder Traversal
==============================================================

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

  TreeNode *build(vector<int> &pre, unordered_map<int, int> &find, int s, int e)
  {
    if (s > e)
      return NULL;
    TreeNode *root = new TreeNode(pre[preI++]);
    if (s == e)
      return root;
    int idx = find[root->val];
    root->left = build(pre, find, s, idx - 1);
    root->right = build(pre, find, idx + 1, e);
    return root;
  }

  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
  {
    unordered_map<int, int> find;
    for (int i = 0; i < inorder.size(); ++i)
      find[inorder[i]] = i;
    return build(preorder, find, 0, inorder.size() - 1);
  }
};
