/*
Serialize and Deserialize Binary Tree
=======================================

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Example 1:
Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [1]
Output: [1]

Example 4:
Input: root = [1,2]
Output: [1,2]

Constraints:
The number of nodes in the tree is in the range [0, 104].
-1000 <= Node.val <= 1000
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec
{
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root)
  {
    if (root == NULL)
      return "";
    queue<TreeNode *> nodes;
    nodes.push(root);
    string res = "";
    while (nodes.size())
    {
      auto node = nodes.front();
      nodes.pop();
      if (node == NULL)
      {
        res += "n ";
        continue;
      }
      res += (to_string(node->val) + " ");
      nodes.push(node->left);
      nodes.push(node->right);
    }
    return res;
  }

  vector<string> tokenize(string data)
  {
    vector<string> ans;
    string curr = data;
    int i = 0;
    while (i <= data.size())
    {
      if (i == data.size() || data[i] == ' ')
      {
        if (curr.size() && curr != " ")
          ans.push_back(curr);
        curr = "";
      }
      else
        curr += data[i];
      i++;
    }

    return ans;
  }

  // Decodes your encoded data to tree.\
    TreeNode* deserialize(string data) {
  if (data == "")
    return NULL;
  vector<string> vstrings = tokenize(data);

  queue<TreeNode *> nodes;
  TreeNode *root = new TreeNode(stoi(vstrings[0]));
  nodes.push(root);

  for (int i = 1; i < vstrings.size(); ++i)
  {
    auto parent = nodes.front();
    nodes.pop();
    if (vstrings[i] != "n")
    {
      TreeNode *left = new TreeNode(stoi(vstrings[i]));
      parent->left = left;
      nodes.push(left);
    }
    if (vstrings[++i] != "n")
    {
      TreeNode *right = new TreeNode(stoi(vstrings[i]));
      parent->right = right;
      nodes.push(right);
    }
  }

  return root;
}
}
;

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
