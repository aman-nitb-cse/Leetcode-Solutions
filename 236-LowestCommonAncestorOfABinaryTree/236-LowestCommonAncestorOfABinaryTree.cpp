// Last updated: 8/20/2026, 9:10:30 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool flag = false;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        TreeNode *left, *right;
        left = lowestCommonAncestor(root->left, p, q);
        right = lowestCommonAncestor(root->right, p, q);
        if(flag) return left ? left : right;
        if((left and right) or ((root == p or root == q) and (left or right))) {
            flag = true;
            return root;
        }
        return (left or right or root == p or root == q) ? root : nullptr;
    }
};