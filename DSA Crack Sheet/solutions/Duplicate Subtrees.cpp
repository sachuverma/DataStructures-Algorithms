/*
Duplicate Subtrees
==================

Given a binary tree of size N, your task is to that find all duplicate subtrees from the given binary tree.

Example:
Input : 
Output : 2 4
         4
Explanation: Above Trees are two 
duplicate subtrees.i.e  and 
Therefore,you need to return above trees 
root in the form of a list.

Your Task:
You don't need to take input. Just complete the function printAllDups() that takes the root node as a parameter and returns an array of Node*, which contains all the duplicate subtree.
Note: Here the Output of every Node printed in the Pre-Order tree traversal format.

Constraints:
1<=T<=100
1<=N<=100
*/

/*
Structure of the node of the binary tree is as
struct Node {
	int data;
	struct Node* left, *right;
};
*/

string NodeToString(Node *root)
{
  if (!root)
    return "N,";
  string ans = to_string(root->data) + ",";
  ans += NodeToString(root->left) + NodeToString(root->right);
  return ans;
}

void dfs(Node *root, vector<Node *> &ans, unordered_map<string, int> &hashes)
{
  if (!root)
    return;

  dfs(root->left, ans, hashes);
  dfs(root->right, ans, hashes);

  auto str = NodeToString(root);
  if (hashes[str] == 1)
    ans.push_back(root);
  hashes[str]++;
}

vector<Node *> printAllDups(Node *root)
{
  if (!root)
    return {};
  vector<Node *> ans;
  unordered_map<string, int> hashes;
  dfs(root, ans, hashes);
  return ans;
}