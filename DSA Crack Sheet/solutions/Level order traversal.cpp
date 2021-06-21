/*
Level order traversal
=====================

Given a binary tree, find its level order traversal.
Level order traversal of a tree is breadth-first traversal for the tree.

Example 1:
Input:
    1
  /   \ 
 3     2
Output:1 3 2

Example 2:
Input:
        10
     /      \
    20       30
  /   \
 40   60
Output:10 20 30 40 60 N N

Your Task:
You don't have to take any input. Complete the function levelOrder() that takes the root node as input parameter and returns a list of integers containing the level order traversal of the given Binary Tree.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 105
*/

vector<int> levelOrder(Node *node)
{
  vector<int> ans;
  queue<Node *> q;
  q.push(node);
  while (q.size())
  {
    auto curr = q.front();
    q.pop();
    ans.push_back(curr->data);
    if (curr->left)
      q.push(curr->left);
    if (curr->right)
      q.push(curr->right);
  }
  return ans;
}
