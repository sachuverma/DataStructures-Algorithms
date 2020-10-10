/*
Serialize and Deserialize BST
=============================

Serialization is converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You need to ensure that a binary search tree can be serialized to a string, and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.



Example 1:
Input: root = [2,1,3]
Output: [2,1,3]

Example 2:
Input: root = []
Output: []


Constraints:
The number of nodes in the tree is in the range [0, 104].
0 <= Node.val <= 104
The input tree is guaranteed to be a binary search tree.
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
            return "#";

        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    int i = 0;
    TreeNode *des(string data)
    {
        if (i < data.size() && data[i] == ',')
            i++;
        if (i >= data.size() || data[i] == '#')
        {
            i += 2;
            return nullptr;
        }
        string s = "";
        while (i < data.size() && data[i] != ',')
        {
            s += data[i];
            i++;
        }

        TreeNode *node = new TreeNode(stoi(s));

        node->left = des(data);
        node->right = des(data);
        cout << node->val << " ";
        return node;
    }
    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {

        return des(data.substr(0, data.size() - 2));
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;