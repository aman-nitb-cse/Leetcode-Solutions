// Last updated: 6/25/2026, 11:18:36 PM
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
    unordered_map<int, int> sum;

    void solve(TreeNode* root, int l = 1){
        if(!root) return;
        sum[l] += root->val;
        solve(root->left, l + 1);
        solve(root->right, l + 1);
    }

    int maxLevelSum(TreeNode* root) {
        solve(root);
        int level = INT_MAX;
        int level_sum = INT_MIN;
        for(auto i = sum.begin(); i != sum.end(); i++){
            if(i->second > level_sum || (i->second == level_sum && level > i->first)){
                level = i->first;
                level_sum = i->second;
            }
        }
        return level;
    }
};