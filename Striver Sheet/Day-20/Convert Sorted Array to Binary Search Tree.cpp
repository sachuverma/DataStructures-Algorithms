/*
Convert Sorted Array to Binary Search Tree
===============================================

Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

Example 1:
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:
Input: nums = [1,3]
Output: [3,1]
Explanation: [1,3] and [3,1] are both a height-balanced BSTs.

Constraints:
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in a strictly increasing order.
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
  TreeNode *build(vector<int> &nums, int s, int e)
  {
    if (s > e)
      return NULL;
    int mid = (s + e) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = build(nums, s, mid - 1);
    root->right = build(nums, mid + 1, e);
    return root;
  }

  TreeNode *sortedArrayToBST(vector<int> &nums)
  {
    return build(nums, 0, nums.size() - 1);
  }
};
