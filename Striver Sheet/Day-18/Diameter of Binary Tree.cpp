/*
Diameter of Binary Tree
=======================

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

Example 1:
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3is the length of the path [4,2,1,3] or [5,2,1,3].

Example 2:
Input: root = [1,2]
Output: 1

Constraints:
The number of nodes in the tree is in the range [1, 104].
-100 <= Node.val <= 100
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
  int maxDepth(TreeNode *root, int &ans)
  {
    if (!root)
      return 0;
    auto left = maxDepth(root->left, ans);
    auto right = maxDepth(root->right, ans);
    ans = max(ans, left + right);
    return max(left, right) + 1;
  }

  int diameterOfBinaryTree(TreeNode *root)
  {
    int ans = 0;
    maxDepth(root, ans);
    return ans;
  }
};
