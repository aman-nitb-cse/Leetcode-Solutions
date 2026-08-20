// Last updated: 8/20/2026, 9:14:00 PM
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
    vector<string> num(TreeNode* root){
        if(!root) return {};
        if(!root->left and !root->right) return {to_string(root->val)};
        vector <string> left, right;
        left = num(root->left);
        right = num(root->right);

        left.insert(left.end(), right.begin(), right.end());

        for(string &s : left){
            s.insert(0, to_string(root->val));
        }
        return left;
    }

    int sumNumbers(TreeNode* root) {
        vector <string> v = num(root);
        int sum = 0;
        for(string &s : v){
            sum += stoi(s);
        }
        return sum;
    }
};