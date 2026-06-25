// Last updated: 6/25/2026, 11:18:38 PM
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
    int solve(TreeNode* root, int sum = 0){
        if(!root) return 0;
        int right = solve(root->right, sum);
        int left = solve(root->left, root->val + right + sum);
        int x = root->val;
        root->val += right + sum;
        return right + left + x;
    }
    TreeNode* bstToGst(TreeNode* root) {
        solve(root);
        return root;
    }
};