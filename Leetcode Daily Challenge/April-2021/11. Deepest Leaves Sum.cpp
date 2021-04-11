/*
Deepest Leaves Sum
==================

Given the root of a binary tree, return the sum of values of its deepest leaves.

Example 1:
Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15

Example 2:
Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19

Constraints:
The number of nodes in the tree is in the range [1, 104].
1 <= Node.val <= 100

Hint #1  
Traverse the tree to find the max depth.

Hint #2  
Traverse the tree again to compute the sum required.
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
  int deepestLeavesSum(TreeNode *root)
  {
    int ans = 0;
    queue<TreeNode *> pending;
    pending.push(root);

    while (pending.size())
    {
      int size = pending.size();
      int curr_ans = 0;
      for (int i = 0; i < size; ++i)
      {
        auto curr = pending.front();
        pending.pop();
        curr_ans += curr->val;
        if (curr->left)
          pending.push(curr->left);
        if (curr->right)
          pending.push(curr->right);
      }
      ans = curr_ans;
    }
    return ans;
  }
};
