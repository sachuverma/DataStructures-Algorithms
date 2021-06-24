/*
ZigZag Tree Traversal
=====================

Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

Example 1:
Input:
        3
      /   \
     2     1
Output:
3 1 2

Example 2:
Input:
           7
        /     \
       9       7
     /  \     /   
    8    8   6     
   /  \
  10   9 
Output:
7 7 9 8 8 6 9 10 

Your Task:
You don't need to read input or print anything. Your task is to complete the function zigZagTraversal() which takes the root node of the Binary Tree as its input and returns a list containing the node values as they appear in the Zig-Zag Level-Order Traversal of the Tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 104
*/

vector<int> zigZagTraversal(Node *root)
{
  vector<int> ans;
  queue<Node *> q;
  q.push(root);
  int z = 0;
  while (q.size())
  {
    vector<int> arr;
    for (int i = q.size(); i > 0; --i)
    {
      auto curr = q.front();
      q.pop();
      arr.push_back(curr->data);
      if (curr->left)
        q.push(curr->left);
      if (curr->right)
        q.push(curr->right);
    }
    if (z)
      reverse(arr.begin(), arr.end());
    z = (z == 0 ? 1 : 0);
    for (auto &i : arr)
      ans.push_back(i);
  }
  return ans;
}
