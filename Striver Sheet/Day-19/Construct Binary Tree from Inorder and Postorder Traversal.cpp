/*
Construct Binary Tree from Inorder and Postorder Traversal
==========================================================

Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: inorder = [-1], postorder = [-1]
Output: [-1]

Constraints:
1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.
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
  int postI;
  TreeNode *build(vector<int> &post, unordered_map<int, int> &find, int s, int e)
  {
    if (s > e)
      return NULL;
    TreeNode *root = new TreeNode(post[postI--]);
    if (s == e)
      return root;
    int idx = find[root->val];
    root->right = build(post, find, idx + 1, e);
    root->left = build(post, find, s, idx - 1);
    return root;
  }

  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
  {
    postI = postorder.size() - 1;
    unordered_map<int, int> find;
    for (int i = 0; i < inorder.size(); ++i)
      find[inorder[i]] = i;

    return build(postorder, find, 0, inorder.size() - 1);
  }
};
