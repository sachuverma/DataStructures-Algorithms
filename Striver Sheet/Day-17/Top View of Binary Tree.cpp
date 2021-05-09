/*
Top View of Binary Tree
=======================

Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node.

Example 1:
Input:
      1
   /    \
  2      3
Output: 2 1 3

Example 2:
Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100
Your Task:
Since this is a function problem. You don't have to take input. Just complete the function topView() that takes root node as parameter and returns a list of nodes visible from the top view from left to right. Print endline after end of printing the top view.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 105
1 ≤ Node Data ≤ 105
*/

//Function to return a list of nodes visible from the top view
//from left to right in Binary Tree.
vector<int> topView(Node *root)
{
  if (!root)
    return {};
  map<int, int> m;
  vector<int> ans;
  queue<pair<Node *, int>> q;
  q.push({root, 0});

  while (q.size())
  {
    auto curr = q.front();
    q.pop();
    if (m.find(curr.second) == m.end())
    {
      m[curr.second] = curr.first->data;
    }

    if (curr.first->left)
      q.push({curr.first->left, curr.second - 1});
    if (curr.first->right)
      q.push({curr.first->right, curr.second + 1});
  }
  for (auto &i : m)
    ans.push_back(i.second);
  return ans;
}
