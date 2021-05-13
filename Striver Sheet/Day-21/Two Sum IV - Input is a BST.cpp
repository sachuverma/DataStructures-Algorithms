/*
Two Sum IV - Input is a BST
===========================

Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:
Input: root = [5,3,6,2,4,null,7], k = 9
Output: true

Example 2:
Input: root = [5,3,6,2,4,null,7], k = 28
Output: false

Example 3:
Input: root = [2,1,3], k = 4
Output: true

Example 4:
Input: root = [2,1,3], k = 1
Output: false

Example 5:
Input: root = [2,1,3], k = 3
Output: true

Constraints:
The number of nodes in the tree is in the range [1, 104].
-104 <= Node.val <= 104
root is guaranteed to be a valid binary search tree.
-105 <= k <= 105
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
  void inorder(TreeNode *root, vector<int> &arr)
  {
    if (!root)
      return;
    inorder(root->left, arr);
    arr.push_back(root->val);
    inorder(root->right, arr);
  }

  bool findTarget(TreeNode *root, int k)
  {
    vector<int> arr;
    inorder(root, arr);

    for (int i = 0; i < arr.size(); ++i)
    {
      int curr = arr[i];
      if (binary_search(arr.begin() + i + 1, arr.end(), k - curr))
        return true;
    }

    return false;
  }
};