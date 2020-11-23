/*
Convert Sorted Array to Binary Search Tree
==========================================

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:
Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5

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
  TreeNode *constructBalancedBST(vector<int> &nums, int left, int right)
  {
    if (left > right)
      return NULL;

    int mid = left + (right - left) / 2;
    TreeNode *current = new TreeNode(nums[mid]);
    current->left = constructBalancedBST(nums, left, mid - 1);
    current->right = constructBalancedBST(nums, mid + 1, right);
    return current;
  }

public:
  TreeNode *sortedArrayToBST(vector<int> &nums)
  {
    if (!nums.size())
      return NULL;
    return constructBalancedBST(nums, 0, nums.size() - 1);
  }
};
