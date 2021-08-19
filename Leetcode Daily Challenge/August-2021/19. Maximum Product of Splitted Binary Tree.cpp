/*
Maximum Product of Splitted Binary Tree
=======================================

Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.

Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.

Note that you need to maximize the answer before taking the mod and not after taking it.

Example 1:
Input: root = [1,2,3,4,5,6]
Output: 110
Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)

Example 2:
Input: root = [1,null,2,3,4,null,null,5,6]
Output: 90
Explanation: Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6)

Example 3:
Input: root = [2,3,9,10,7,8,6,5,4,11,1]
Output: 1025

Example 4:
Input: root = [1,1]
Output: 1

Constraints:
The number of nodes in the tree is in the range [2, 5 * 104].
1 <= Node.val <= 104
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#define ll long long
int M = 1e9 + 7;

class Solution
{
public:
    int dfs1(TreeNode *root)
    {
        if (!root)
            return 0;
        return root->val + dfs1(root->left) + dfs1(root->right);
    }

    int dfs2(TreeNode *root, ll &ans, ll totalSum)
    {
        int sumHere = root->val;

        if (root->left)
            sumHere += dfs2(root->left, ans, totalSum);
        if (root->right)
            sumHere += dfs2(root->right, ans, totalSum);

        ans = max(ans, sumHere * (totalSum - sumHere));
        return sumHere;
    }

    int maxProduct(TreeNode *root)
    {
        ll fullSum = dfs1(root);
        ll ans = 0;

        dfs2(root, ans, fullSum);

        return ans % M;
    }
};