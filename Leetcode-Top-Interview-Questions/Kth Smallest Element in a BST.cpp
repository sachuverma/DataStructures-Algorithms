/*
Kth Smallest Element in a BST
=============================

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Example 1:
Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1

Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Constraints:
The number of elements of the BST is between 1 to 10^4.
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Hint #1  
Try to utilize the property of a BST.

Hint #2  
Try in-order traversal. (Credits to @chan13)

Hint #3  
What if you could modify the BST node's structure?

Hint #4  
The optimal runtime complexity is O(height of BST).
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
  void inorder(TreeNode *root, vector<int> &ans, int k)
  {
    if (!root)
      return;
    inorder(root->left, ans, k);
    if (++ans[0] == k)
      ans[1] = root->val;
    inorder(root->right, ans, k);
  }

public:
  int kthSmallest(TreeNode *root, int k)
  {
    vector<int> ans = {0, 0};
    inorder(root, ans, k);
    return ans[1];
  }
};
