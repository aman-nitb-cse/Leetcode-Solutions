// Last updated: 8/20/2026, 9:10:50 PM
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
    int count = 0, k;
    int solve(TreeNode* root){
        if(!root) return -1;
        int left = solve(root->left);
        if(left != -1) return left;
        if(count == k) return root->val;
        count++;
        return solve(root->right);
    }
    int kthSmallest(TreeNode* root, int _k) {
        k = _k - 1;
        return solve(root);
    }
};