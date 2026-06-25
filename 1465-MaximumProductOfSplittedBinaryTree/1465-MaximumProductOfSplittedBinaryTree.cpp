// Last updated: 6/25/2026, 11:16:44 PM
class Solution {
public:
    long long sum = 0; 
    int mod = 1e9 + 7;
    long long maxi = LLONG_MIN;
    void getSum(TreeNode* root){
        if(!root) return;
        sum += root->val;
        getSum(root->left);
        getSum(root->right);
    }

    long long solve(TreeNode* root){
        if(!root) return 0;
        long long left = solve(root->left);
        long long right = solve(root->right);

        long long a = root->val + left + right;
        long long b = sum - a;

        maxi = max(maxi, a * b);
        return a;
    }

    int maxProduct(TreeNode* root) {
        getSum(root);
        solve(root);
        return maxi % mod;
    }
};