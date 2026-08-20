// Last updated: 8/20/2026, 9:12:01 PM
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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector <int> left, right;
        left = rightSideView(root->left);
        right = rightSideView(root->right);
        // left > right
        for(int i = right.size(); i < left.size(); i++){
            right.push_back(left[i]);
        }
        right.insert(right.begin(), root->val);
        return right;
    }
};