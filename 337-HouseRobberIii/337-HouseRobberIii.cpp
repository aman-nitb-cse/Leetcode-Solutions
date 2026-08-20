// Last updated: 8/20/2026, 9:08:24 PM
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
    pair<int, int> solve(TreeNode* root){
        if(!root) return {0, 0};
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        return { left.second + right.second + root->val, max(right.first, right.second) + max(left.first, left.second) };
    }
    int rob(TreeNode* root) {
        pair<int, int> p = solve(root);
        return max(p.first, p.second);
    }
};