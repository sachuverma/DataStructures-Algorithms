/*
Brothers From Different Roots
=============================

Given two BSTs containing N1 and N2 distinct nodes respectively and given a value x. Your task is to complete the function countPairs(), that returns the count of all pairs from both the BSTs whose sum is equal to x.

Examples:
Input : BST 1:    5        
                /   \      
               3     7      
              / \   / \    
             2  4  6   8   

        BST 2:    10        
                /   \      
               6     15      
              / \   /  \    
             3  8  11  18
        x = 16
    
Output : 3
The pairs are:
(5, 11), (6, 10) and (8, 8)
Input:
The function takes three arguments as input, first the reference pointer to the root(root1) of the BST1, then reference pointer to the root(root2) of the BST2 and last the element X.
There will be T test cases and for each test case the function will be called separately.

Output:
For each test cases print the required number of pairs on new line.

Constraints:
1<=T<=100
1<=N<=103

Example:
Input:
2
7
5 3 7 2 4 6 8
7
10 6 15 3 8 11 18
16
6
10 20 30 40 5 1
5
25 35 10 15 5
30
Output:
3
2
*/

bool search(Node *root, int x)
{
  if (!root)
    return false;
  if (root->data == x)
    return true;
  else if (root->data < x)
    return search(root->right, x);
  return search(root->left, x);
}

void dfs(Node *root1, Node *root2, int x, int &ans)
{
  if (!root1)
    return;
  int tar = root1->data;
  if (search(root2, x - tar))
    ans++;
  dfs(root1->left, root2, x, ans);
  dfs(root1->right, root2, x, ans);
}

int countPairs(Node *root1, Node *root2, int x)
{
  int ans = 0;
  dfs(root1, root2, x, ans);
  return ans;
}