/*
Binary Tree Postorder Traversal
===============================

Given the root of a binary tree, return the postorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [3,2,1]

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
Output: [2,1]

Constraints:
The number of the nodes in the tree is in the range [0, 100].
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
  vector<int> postorderTraversal(TreeNode *root)
  {
    vector<int> ans;
    auto curr = root;
    stack<TreeNode *> st, ss;
    st.push(root);

    while (st.size())
    {
      curr = st.top();
      st.pop();
      if (!curr)
        break;
      ss.push(curr);
      if (curr->left)
        st.push(curr->left);
      if (curr->right)
        st.push(curr->right);
    }

    while (ss.size())
    {
      ans.push_back(ss.top()->val);
      ss.pop();
    }

    return ans;
  }
};
