// Last updated: 8/20/2026, 9:14:44 PM
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
    bool hasPathSum(TreeNode* root, int k) {
        if(!root) return false;
        k -= root->val;
        if(!root->left and !root->right) return !k;
        return hasPathSum(root->left, k) or hasPathSum(root->right, k);
    }
};