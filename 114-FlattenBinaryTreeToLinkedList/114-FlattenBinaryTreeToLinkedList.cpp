// Last updated: 8/20/2026, 9:14:42 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* flatten_tree(TreeNode* root) { // modify tree and return tail
        if (!root)
            return NULL;
        TreeNode* left_tail = flatten_tree(root->left);
        TreeNode* right_tail = flatten_tree(root->right);

        if (!left_tail && !right_tail)
            return root;
        if (!left_tail)
            return right_tail;

        left_tail->right = root->right;
        root->right = root->left;
        root->left = NULL;
        return right_tail ? right_tail : left_tail;
    }

    void flatten(TreeNode* root) { flatten_tree(root); }
};