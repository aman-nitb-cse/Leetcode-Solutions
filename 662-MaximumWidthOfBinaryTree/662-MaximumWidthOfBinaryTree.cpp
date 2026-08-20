// Last updated: 8/20/2026, 9:01:20 PM
class Solution {
public:
    __uint128_t ans = 0;
    vector<__uint128_t> mini;

    void dfs(TreeNode* root,int r,__uint128_t c){
        if(!root) return;

        if(mini.size() <= r)
            mini.push_back(c);

        ans = max(ans,c - mini[r] + 1);

        dfs(root->left,r + 1,c << 1);
        dfs(root->right,r + 1, (c << 1) + 1);
    }

    int widthOfBinaryTree(TreeNode* root) {
        dfs(root,0,1);
        return (long long)ans;
    }
};