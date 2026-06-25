// Last updated: 6/25/2026, 11:37:15 PM
class Solution {
public:
    int ans = 0;
    int solve(TreeNode* root){
        if(!root) return 0;

        int left = solve(root->left);
        int right = solve(root->right);

        int l = (root->left && root->left->val == root->val) ? left : 0;
        int r = (root->right && root->right->val == root->val) ? right : 0;

        ans = max(ans, 1 + l + r);
        
        return 1 + max(l, r);
    }
    int longestUnivaluePath(TreeNode* root) {
        solve(root);
        return max(0, ans - 1);
    }
};