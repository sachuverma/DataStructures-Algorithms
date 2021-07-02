/*
Preorder to BST
===============

Given an array arr[] of N nodes representing preorder traversal of BST. The task is to print its postorder traversal.

Example 1:
Input:
N = 5
arr[]  = {40,30,35,80,100}
Output: 35 30 100 80 40
Explanation: PreOrder: 40 30 35 80 100
InOrder: 30 35 40 80 100
Therefore, the BST will be:
              40
           /      \
         30       80
           \        \   
           35      100
Hence, the postOrder traversal will
be: 35 30 100 80 40

Example 2:
Input:
N = 8
arr[]  = {40,30,32,35,80,90,100,120}
Output: 35 32 30 120 100 90 80 40
Your Task:
You need to complete the given function and return the root of the tree. The driver code will then use this root to print the post order traversal.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 103
1 <= arr[i] <= 104
*/

Node *build(int pre[], int s, int e, unordered_map<int, int> &next_greater)
{
  if (s > e)
    return NULL;
  if (s == e)
  {
    Node *root = new Node();
    root->data = pre[s];
    return root;
  }

  Node *root = new Node();
  root->data = pre[s];

  int lb = next_greater[s];

  root->left = build(pre, s + 1, lb - 1, next_greater);
  root->right = build(pre, lb, e, next_greater);
  return root;
}

//Function that constructs BST from its preorder traversal.
Node *constructTree(int pre[], int n)
{
  stack<int> st;
  unordered_map<int, int> next_greater;
  next_greater[n - 1] = n;
  st.push(n - 1);

  for (int i = n - 2; i >= 0; --i)
  {
    while (st.size() > 0 && pre[st.top()] <= pre[i])
      st.pop();
    next_greater[i] = n;
    if (st.size())
      next_greater[i] = st.top();
    st.push(i);
  }

  // for(auto &i: next_greater) cout<<i.first<<" "<<i.second<<endl;
  return build(pre, 0, n - 1, next_greater);
}