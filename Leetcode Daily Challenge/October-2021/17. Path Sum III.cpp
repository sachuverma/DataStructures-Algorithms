/*Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.
 The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

Example 1:
Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.

Example 2:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3

Constraints :
The number of nodes in the tree is in the range [0, 1000].
-10^9 <= Node.val <= 10^9
-1000 <= targetSum <= 1000

*/

//-------------------------------------Approach--------------------------------------------------------------------------------
// This problem is same like finding all sub arrays with sum k
// so here we will use the basic properties of prefix sum array
// For every path we will maintain a frequency array of prefix sum
// let say we have array 1,2,3,... l......r.....n
// if we want sum of elements from range l to r we can get it using prefix sum
// we will maintain prefix sum at every index and then sum of elements from l to r = pref[r] - pref[l-1]
// so similar concept we are going to use in this question as well

// let say reached at node n and we have current sum
// using the above formula we can get target sum = current sum - x
// from equation x = current sum - target sum
// x is value we need to find and which may be present in path which we traversed uptill now
// so to check if it is present we will maintain a frequency array of prefix sum
// which means every node we will increment freq[current_sum + node->val] += 1 -> here freq is the frequency array
// so by maintaining frequency array we can know if x is present and also the count of x which are the
// so the number of target sum we can form will be the number x we get in the path which we traversed uptill now
// and we keep adding it out our ans to get the final count of the number of paths where the sum of the values along the path equals targetSum



//-----------------Time and Space Complexity --------------------
// since we are traversing normal dfs its time complexity will be O(n)
// Space complexity : as we are using hash map array which will take O(n) space .
// here n = number of nodes in the binary tree


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
    int req_sum;
    int ans=0;
    unordered_map<int,int>freq;
    void dfs(TreeNode *node ,int cur_sum){
         if(node==NULL){  // base condition
             return ;
         }
         // here x that we talked in approach is equal to cur_sum+node->val - req_sum

         ans+=freq[cur_sum+node->val - req_sum];         // so from the number of x present uptill now we can make our target sum therefore adding it freq[x] in ans

         freq [cur_sum+node->val]++;                    // adding the node value to current sum and increasing its frequency count

         dfs(node->left,cur_sum+node->val);             // running independent dfs on left child : node->left;

         dfs(node->right,cur_sum+node->val);            // running independent dfs on right child : node->right

         freq [cur_sum+node->val]--;                   // since we have traversed both right child and left child of node we must reduce the freq[cur_sum+node->val]
                                                       // from our freq array else it may cause overriding issue and which may lead to wrong ans
    }
    int pathSum(TreeNode* root, int targetSum) {

        req_sum = targetSum;    // making req_sum as global targetSum

        freq[0]=1;          // making freq[0] as 1 because if the current sum is equal to target sum than x = 0 and we must have freq[x] as 1 initially else we will miss this condition in our ans

        dfs(root,0);

        return ans;
    }
};
