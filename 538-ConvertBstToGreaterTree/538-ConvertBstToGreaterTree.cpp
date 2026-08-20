// Last updated: 8/20/2026, 9:03:21 PM
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
    TreeNode* convertBST(TreeNode* root) {
        solve(root);
        return root;
    }
};