/*
Kth largest element in BST
==========================

Given a Binary search tree. Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.

Example 1:
Input:
      4
    /   \
   2     9
k = 2 
Output: 4

Example 2:
Input:
       9
        \ 
          10
K = 1
Output: 10

Your Task:
You don't need to read input or print anything. Your task is to complete the function kthLargest() which takes the root of the BST and an integer K as inputs and returns the Kth largest element in the given BST.

Expected Time Complexity: O(H + K).
Expected Auxiliary Space: O(H)

Constraints:
1 <= N <= 1000
1 <= K <= N
*/

class Solution
{
public:
  int ans = INT_MIN;
  void inorder(Node *root, int &k)
  {
    if (k == 0 || !root)
      return;
    inorder(root->right, k);
    k--;
    if (k == 0)
      ans = root->data;
    inorder(root->left, k);
  }

  int kthLargest(Node *root, int K)
  {
    inorder(root, K);
    return ans;
  }
};