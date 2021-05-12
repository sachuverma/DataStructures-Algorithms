/*
Predecessor and Successor
=========================

There is BST given with root node with key part as integer only. You need to find the inorder successor and predecessor of a given key. In case, if the either of predecessor or successor is not found print -1.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains n denoting the number of edges of the BST. The next line contains the edges of the BST. The last line contains the key.

Output:
Print the predecessor followed by successor for the given key. If the predecessor or successor is not found print -1.

Constraints:
1<=T<=100
1<=n<=100
1<=data of node<=100
1<=key<=100

Example:
Input:
2
6
50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
65
6
50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
100

Output:
60 70
80 -1
*/

/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{

  if (!root)
    return;
  if (root->key == key)
  {

    if (root->left)
    {
      auto rt_max = root->left;
      while (rt_max->right)
        rt_max = rt_max->right;
      pre = rt_max;
    }

    if (root->right)
    {
      auto rt_max = root->right;
      while (rt_max->left)
        rt_max = rt_max->left;
      suc = rt_max;
    }
    return;
  }

  else if (root->key > key)
  {
    suc = root;
    findPreSuc(root->left, pre, suc, key);
  }
  else
  {
    pre = root;
    findPreSuc(root->right, pre, suc, key);
  }
}