/*
Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.

Example 1:
Input: root = [1,2,3,4], x = 4, y = 3
Output: false

Example 2:
Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true

Example 3:
Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false

Constraint :
The number of nodes in the tree is in the range [2, 100].
1 <= Node.val <= 100
Each node has a unique value.
x != y
x and y are exist in the tree.

*/
//------------------------------------Approach-------------------------------------------------------

// we will do a normal dfs traversal with function having two parameter namely dfs(TreeNode*node,int dis)
// node will be the current node on which we are
// dis is the distance of that node from the root node when is also the depth of node
// According to problem we also need to find the parent of the node
// So we will make the current node as parent of node->right and node->left if they are not null
// At last we will check the condition according to problem that
// Two node are cousin node if their depth are equal that is distance from root node is equal and they both have different parent
// NOTE : As all value are different we do not have to worry about data overriding problem

//-------------------------------Time and Space Complexity---------------------------------------------
// since we are doing normal dfs therefore its time complexity will be O(n)
// As we using Depth and parent array to store depth and parent of node respectively therefore space complexity will be O(n)

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
class Solution {
public:
    int depth[102];
    int parent[102];
    void dfs(TreeNode*node,int dis){

        depth[node->val] = dis;                         // Allocating the current dis to value of node

        if(node->left==NULL && node->right==NULL){
            return ;                                    // base condition i.e. left and right child are null we will return from function
        }
        if(node->left!=NULL){                          // if left child is not null we are making parent of left child as node->val and calling function dfs on it
            TreeNode *left_child = node->left;

            parent[left_child->val] = node->val;

            dfs(left_child,dis+1);                     // as we going one node far from root node we will increase pas dis+1 as distance parameter in dfs call
        }
        if(node->right!=NULL){                        // if left child is not null we are making parent of left child as node->val and calling function dfs on it
            TreeNode *right_child = node->right;

            parent[right_child->val] = node->val;

            dfs(right_child,dis+1);
        }

    }
    bool isCousins(TreeNode* root, int x, int y) {

        dfs(root,0);                                             // Starting the dfs call and initializing the dis parameter as 0 as we know the distance of root from root will be 0

        if(parent[x]!=parent[y] && (depth[x] == depth[y])){      //if the required condition satisfies then we will return true else return false
            return true;
        }
        else{
            return false;
        }
    }
};
