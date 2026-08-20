// Last updated: 8/20/2026, 8:26:50 PM
class Solution {
public:
    int ans = 0;
    int f(TreeNode* root){
        if(!root) return -1;

        int maxi = max({f(root->left), f(root->right), root->val});

        ans += (maxi == root->val);

        return maxi;
    }
    int countDominantNodes(TreeNode* root) {
        f(root);
        return ans;
    }
};