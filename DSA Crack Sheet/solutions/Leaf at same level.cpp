/*
Leaf at same level
==================

Given a Binary Tree, check if all leaves are at same level or not.

Example 1:
Input: 
            1
          /   \
         2     3

Output: 1
Explanation: 
Leaves 2 and 3 are at same level.

Example 2:
Input:
            10
          /    \
        20      30
       /  \        
     10    15

Output: 0
Explanation:
Leaves 10, 15 and 30 are not at same level.

Your Task: 
You dont need to read input or print anything. Complete the function check() which takes root node as input parameter and returns true/false depending on whether all the leaf nodes are at the same level or not.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)

Constraints:
1 ≤ N ≤ 10^3
*/

bool helper(Node *root, int &level, int depth)
{
  if (!root->left && !root->right)
  {
    if (level == -1)
      level = depth;
    else if (level != depth)
      return false;
    return true;
  }

  if (root->left && !helper(root->left, level, depth + 1))
    return false;
  if (root->right && !helper(root->right, level, depth + 1))
    return false;
  ;
  return true;
}

bool check(Node *root)
{
  if (!root)
    return true;
  int level = -1;
  return helper(root, level, 0);
}