/*
Construct Binary Tree from Preorder and Inorder Traversal
=========================================================

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given
preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
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
  TreeNode *helper(vector<int> &inorder, vector<int> &preorder, int inS, int inE, int preS, int preE)
  {
    if (inS > inE || preS > preE)
      return nullptr;
    int rootData = preorder[preS];

    int inIndex = -1;
    for (int i = inS; i <= inE; ++i)
    {
      if (rootData == inorder[i])
      {
        inIndex = i;
        break;
      }
    }

    int lPreS = preS + 1;
    int lInS = inS;
    int rPreE = preE;
    int rInE = inE;

    int lInE = inIndex - 1;
    int lPreE = lInE - lInS + lPreS;
    int rPreS = lPreE + 1;
    int rInS = inIndex + 1;

    TreeNode *root = new TreeNode(rootData);
    root->left = helper(inorder, preorder, lInS, lInE, lPreS, lPreE);
    root->right = helper(inorder, preorder, rInS, rInE, rPreS, rPreE);
    return root;
  }

public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
  {
    int n = inorder.size();
    return helper(inorder, preorder, 0, n - 1, 0, n - 1);
  }
};
