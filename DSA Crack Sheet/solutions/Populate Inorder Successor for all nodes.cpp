/*
Populate Inorder Successor for all nodes
===========================================

Given a Binary Tree, write a function to populate next pointer for all nodes. The next pointer for every node should be set to point to inorder successor.

Example 1:
Input:
           10
       /  \
      8    12
     /
    3
  
Output: 3->8 8->10 10->12 12->-1
Explanation: The inorder of the above tree is :
3 8 10 12. So the next pointer of node 3 is 
pointing to 8 , next pointer of 8 is pointing
to 10 and so on.And next pointer of 12 is
pointing to -1 as there is no inorder successor 
of 12.

Example 2:
Input:
           1
      /   \
     2     3
Output: 2->1 1->3 3->-1 
Your Task:
You do not need to read input or print anything. Your task is to complete the function populateNext() that takes the root node of the binary tree as input parameter.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
Constraints:
1<=n<=10^5
1<=data of the node<=10^5
*/

Node *prev = NULL;

void populateNext(Node *root)
{
  if (!root)
    return;
  populateNext(root->right);
  root->next = prev;
  prev = root;
  populateNext(root->left);
}