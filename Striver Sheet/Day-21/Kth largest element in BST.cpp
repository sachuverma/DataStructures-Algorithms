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
  void inorder(Node *root, vector<int> &arr)
  {
    if (!root)
      return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
  }
  int kthLargest(Node *root, int K)
  {
    //Your code here
    vector<int> arr;
    inorder(root, arr);
    return arr[arr.size() - K];
  }
};