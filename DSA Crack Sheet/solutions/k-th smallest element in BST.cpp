/*
k-th smallest element in BST
============================

Given a BST and an integer K. Find the Kth Smallest element in the BST. 

Example 1:
Input:
      2
    /   \
   1     3
K = 2
Output: 2

Example 2:
Input:
        2
      /  \
     1    3
K = 5
Output: -1
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function KthSmallestElement() which takes the root of the BST and integer K as inputs and return the Kth smallest element in the BST, if no such element exists return -1.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1<=Number of nodes<=100000
*/

int ans = -1;
void inorder(Node *root, int &k)
{
  if (k == 0 || !root)
    return;
  inorder(root->left, k);
  k--;
  if (k == 0)
  {
    ans = root->data;
    return;
  }
  inorder(root->right, k);
}

// Return the Kth smallest element in the given BST
int KthSmallestElement(Node *root, int K)
{
  //add code here.
  inorder(root, K);
  return ans;
}