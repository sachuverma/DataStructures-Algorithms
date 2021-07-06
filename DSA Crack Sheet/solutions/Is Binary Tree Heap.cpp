/*
Is Binary Tree Heap
===================

Given a binary tree you need to check if it follows max heap property or not.

Input:
The task is to complete the method which takes one argument, root of Binary Tree. The struct Node has a data part which stores the data, pointer to left child and pointer to right child.There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return true if property holds else false.

Example 1:
Input:
      5
    /  \
   2    3
Output: 1

Example 2:
Input:
       10
     /   \
    20   30 
  /   \
 40   60
Output: 0

Constraints:
1 ≤ Number of nodes ≤ 100
1 ≤ Data of a node ≤ 1000
*/

int count(Node *root)
{
  if (root == NULL)
    return 0;
  return 1 + count(root->left) + count(root->right);
}

bool iscomplete(Node *root, int idx, int ct)
{
  if (root == NULL)
    return true;
  if (idx >= ct)
    return false;
  return (iscomplete(root->left, 2 * idx + 1, ct) && iscomplete(root->right, 2 * idx + 2, ct));
}

bool isheaputil(Node *root)
{
  if (root->left == NULL && root->right == NULL)
    return true;
  if (root->right == NULL)
    return (root->data >= root->left->data);
  else
  {
    if ((root->data >= root->left->data) && (root->data >= root->right->data))
      return (isheaputil(root->left) && isheaputil(root->right));
    else
      return false;
  }
}

bool isHeap(Node *tree)
{
  int ct = count(tree);
  int idx = 0;
  if (iscomplete(tree, idx, ct) && isheaputil(tree))
    return true;
  return false;
}