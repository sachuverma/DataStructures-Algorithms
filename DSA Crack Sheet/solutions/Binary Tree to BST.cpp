/*
Binary Tree to BST
==================

Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps the original structure of Binary Tree intact.

Example 1:
Input:
      1
    /   \
   2     3
Output: 1 2 3

Example 2:
Input:
          1
       /    \
     2       3
   /        
 4       
Output: 1 2 3 4
Explanation:
The converted BST will be

        3
      /   \
    2     4
  /
 1

Your Task:
You don't need to read input or print anything. Your task is to complete the function binaryTreeToBST() which takes the root of the Binary tree as input and returns the root of the BST. The driver code will print inorder traversal of the converted BST.

Expected Time Complexity: O(NLogN).
Expected Auxiliary Space: O(N).
*/

void inorder(Node *root, vector<int> &ans)
{
  if (!root)
    return;

  inorder(root->left, ans);
  ans.push_back(root->data);
  inorder(root->right, ans);
}

void replaceValues(Node *&root, vector<int> &in, int &i)
{
  if (!root)
    return;

  replaceValues(root->left, in, i);
  root->data = in[i++];
  replaceValues(root->right, in, i);
}

Node *binaryTreeToBST(Node *root)
{
  vector<int> in;
  inorder(root, in);
  sort(in.begin(), in.end());

  int i = 0;
  replaceValues(root, in, i);
  return root;
}