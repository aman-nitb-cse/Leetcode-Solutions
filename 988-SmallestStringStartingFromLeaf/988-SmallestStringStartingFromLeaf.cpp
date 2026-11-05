// Last updated: 11/6/2026, 5:09:41 AM
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
    vector<string> help(TreeNode* root){
        if(!root) return {};
        if(!root->left and !root->right){
            string s = "";
            s += (char)(root->val + 'a');
            return {s};
        }
        vector<string> left, right;
        left = help(root->left);
        right = help(root->right);

        left.insert(left.end(), right.begin(), right.end());
        for(string &s : left){
            s += (char)(root->val + 'a');
        }
        return left;
    }
    string smallestFromLeaf(TreeNode* root) {
        vector<string> v = help(root);
        sort(v.begin(), v.end());
        return v.front();
    }
};