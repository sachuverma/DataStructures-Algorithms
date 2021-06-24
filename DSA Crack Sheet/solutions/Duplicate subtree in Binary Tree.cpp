/*
Duplicate subtree in Binary Tree
================================

Given a binary tree, find out whether it contains a duplicate sub-tree of size two or more, or not.

Example 1 :

Input : 
        1
      /   \ 
    2       3
  /   \       \    
4     5       2     
              /  \    
            4    5

Output : 1
Explanation : 
    2     
  /  \    
4     5
is the duplicate sub-tree.

Example 2 :
Input : 
    1
  /   \ 
2       3
Output: 0
Explanation: There is no duplicate sub-tree 
in the given binary tree.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function dupSub() which takes root of the tree as the only arguement and returns 1 if the binary tree contains a duplicate sub-tree of size two or more, else 0.

Note: Two same leaf nodes are not considered as subtree as size of a leaf node is one.

Constraints:
1<=length of string<=100
*/

string treeString(Node *root)
{
  if (!root)
    return "N,";
  string ans = to_string(root->data) + ",";
  ans += treeString(root->left);
  ans += treeString(root->right);
  return ans;
}

int countNodes(Node *root)
{
  if (!root)
    return 0;
  return 1 + countNodes(root->left) + countNodes(root->right);
}

bool helper(Node *root, unordered_set<string> &Set)
{
  if (!root)
    return false;
  auto str = treeString(root);
  if (Set.find(str) != Set.end() && countNodes(root) > 1)
    return true;
  Set.insert(str);
  return helper(root->left, Set) || helper(root->right, Set);
}

/*This function returns true if the tree contains 
a duplicate subtree of size 2 or more else returns false*/
bool dupSub(Node *root)
{
  unordered_set<string> Set;
  return helper(root, Set);
}