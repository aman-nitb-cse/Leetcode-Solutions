// Last updated: 6/25/2026, 11:19:22 PM
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