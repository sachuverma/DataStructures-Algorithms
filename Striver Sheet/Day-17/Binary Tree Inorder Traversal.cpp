/*
Binary Tree Inorder Traversal
=============================

Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [1,3,2]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [1]
Output: [1]

Example 4:
Input: root = [1,2]
Output: [2,1]

Example 5:
Input: root = [1,null,2]
Output: [1,2]

Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

Follow up:
Recursive solution is trivial, could you do it iteratively?
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
  vector<int> inorderTraversal(TreeNode *root)
  {
    vector<int> ans;
    stack<TreeNode *> st;
    auto curr = root;

    while (curr || st.size())
    {
      if (!curr)
      {
        curr = st.top();
        st.pop();
        ans.push_back(curr->val);
        curr = curr->right;
      }

      while (curr)
      {
        st.push(curr);
        curr = curr->left;
      }
    }

    return ans;
  }
};
