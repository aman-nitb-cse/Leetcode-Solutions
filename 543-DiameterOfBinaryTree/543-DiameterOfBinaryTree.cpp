// Last updated: 8/20/2026, 9:03:14 PM
class Solution {
public:
    int ans = 0;
    int solve(TreeNode* root){
        if(!root) return 0;
        int left = solve(root->left);
        int right = solve(root->right);

        ans = max(ans, left + right);

        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return ans;
    }
};