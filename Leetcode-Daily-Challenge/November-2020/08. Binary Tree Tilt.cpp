/*
Binary Tree Tilt
================

Given the root of a binary tree, return the sum of every tree node's tilt.

The tilt of a tree node is the absolute difference between the sum of all left subtree node values and all right subtree node values. If a node does not have a left child, then the sum of the left subtree node values is treated as 0. The rule is similar if there the node does not have a right child.


Example 1:
Input: root = [1,2,3]
Output: 1
Explanation: 
Tilt of node 2 : |0-0| = 0 (no children)
Tilt of node 3 : |0-0| = 0 (no children)
Tile of node 1 : |2-3| = 1 (left subtree is just left child, so sum is 2; right subtree is just right child, so sum is 3)
Sum of every tilt : 0 + 0 + 1 = 1

Example 2:
Input: root = [4,2,9,3,5,null,7]
Output: 15
Explanation: 
Tilt of node 3 : |0-0| = 0 (no children)
Tilt of node 5 : |0-0| = 0 (no children)
Tilt of node 7 : |0-0| = 0 (no children)
Tilt of node 2 : |3-5| = 2 (left subtree is just left child, so sum is 3; right subtree is just right child, so sum is 5)
Tilt of node 9 : |0-7| = 7 (no left child, so sum is 0; right subtree is just right child, so sum is 7)
Tilt of node 4 : |(3+5+2)-(9+7)| = |10-16| = 6 (left subtree values are 3, 5, and 2, which sums to 10; right subtree values are 9 and 7, which sums to 16)
Sum of every tilt : 0 + 0 + 0 + 2 + 7 + 6 = 15

Example 3:
Input: root = [21,7,14,1,1,2,2,3,3]
Output: 9
 

Constraints:
The number of nodes in the tree is in the range [0, 104].
-1000 <= Node.val <= 1000

Hint #1  
Don't think too much, this is an easy problem. Take some small tree as an example.

Hint #2  
Can a parent node use the values of its child nodes? How will you implement it?

Hint #3  
May be recursion and tree traversal can help you in implementing.

Hint #4  
What about postorder traversal, using values of left and right childs?
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
  int treeSum(TreeNode *root)
  {
    if (!root)
      return 0;
    int ans = root->val;
    if (root->left)
      ans += treeSum(root->left);
    if (root->right)
      ans += treeSum(root->right);
    return ans;
  }

  void findTilt(TreeNode *root, int &ans)
  {
    if (!root)
      return;

    int lVal = root->left ? treeSum(root->left) : 0;
    int rVal = root->right ? treeSum(root->right) : 0;

    int newVal = abs(lVal - rVal);
    root->val = newVal;
    ans += newVal;

    if (root->left)
      findTilt(root->left, ans);
    if (root->right)
      findTilt(root->right, ans);
  }

public:
  int findTilt(TreeNode *root)
  {
    int ans = 0;
    findTilt(root, ans);
    return ans;
  }
};
