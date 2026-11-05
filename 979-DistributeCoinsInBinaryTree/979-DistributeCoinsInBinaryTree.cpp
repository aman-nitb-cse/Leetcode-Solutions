// Last updated: 11/6/2026, 5:10:01 AM
class Solution {
public:
    int moves = 0;
    int dfs(TreeNode* root){
        if(!root) return 0;

        int coins = root->val + dfs(root->left) + dfs(root->right);
        moves += abs(coins - 1);
        return coins - 1;
    }
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return moves;
    }
};