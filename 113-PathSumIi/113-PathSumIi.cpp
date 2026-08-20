// Last updated: 8/20/2026, 9:14:46 PM
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
    vector<vector<int>> pathSum(TreeNode* root, int k) {
        if(!root) return {};
        k -= root->val;
        if(!root->left and !root->right){
            if(k) return {};
            return {{root->val}};
        }
        vector<vector<int>> left, right;
        left = pathSum(root->left, k);
        right = pathSum(root->right, k);
        left.insert(left.end(), right.begin(), right.end());

        for(vector <int> &v : left){
            v.insert(v.begin(), root->val);
        }

        return left;
    }
};