// Last updated: 6/25/2026, 11:19:33 PM
class Solution {
public:
    vector<int> dfs(TreeNode* root){ // {hasCam, covered, notCovered}
        if(!root) return {(int)1e9, 0, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);
        
        return {
            1 + ranges::min(left) + ranges::min(right), 
            min(
                left[0] + min(right[0], right[1]),
                right[0] + min(left[0], left[1])
            ), 
            left[1] + right[1]
        };
    }

    int minCameraCover(TreeNode* root) {
        auto res = dfs(root);
        return min(res[0], res[1]);
    }
};