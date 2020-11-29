/*
Recover Binary Search Tree
==========================

You are given the root of a binary search tree (BST), where exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

Follow up: A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?


Example 1:
Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]

Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.

Example 2:
Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]

Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.


Constraints:
The number of nodes in the tree is in the range [2, 1000].
-231 <= Node.val <= 231 - 1
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
  TreeNode *first = NULL, *last = NULL;
  TreeNode *prev = new TreeNode(INT_MIN);

  void inorder(TreeNode *node)
  {
    if (node == NULL)
      return;
    inorder(node->left);

    if (first == NULL && prev->val > node->val)
      first = prev;
    if (first != NULL && prev->val > node->val)
      last = node;
    prev = node;

    inorder(node->right);
  }

public:
  void recoverTree(TreeNode *root)
  {
    if (!root)
      return;
    inorder(root);

    int temp = first->val;
    first->val = last->val;
    last->val = temp;
  }
};
