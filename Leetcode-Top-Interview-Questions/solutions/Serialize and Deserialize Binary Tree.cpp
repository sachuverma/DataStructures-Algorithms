/*
Serialize and Deserialize Binary Tree
=====================================

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
  int helper(string &data)
  {
    int pos = data.find(',');
    int val = stoi(data.substr(0, pos));
    data = data.substr(pos + 1);
    return val;
  }

public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root)
  {
    if (root == nullptr)
      return "#";
    return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data)
  {
    return mydeserialize(data);
  }

  TreeNode *mydeserialize(string &data)
  {
    if (data[0] == '#')
    {
      if (data.size() > 1)
        data = data.substr(2);
      return nullptr;
    }
    else
    {
      TreeNode *node = new TreeNode(helper(data));
      node->left = mydeserialize(data);
      node->right = mydeserialize(data);
      return node;
    }
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
