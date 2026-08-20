// Last updated: 8/20/2026, 9:10:05 PM
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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        if(!root->left and !root->right){
            return {to_string(root->val)};
        }
        vector <string> left, right;
        left = binaryTreePaths(root->left);
        right = binaryTreePaths(root->right);

        right.insert(right.end(), left.begin(), left.end());

        for(string &s : right){
            s.insert(0, to_string(root->val) + "->");
        }
        return right;
    }
};