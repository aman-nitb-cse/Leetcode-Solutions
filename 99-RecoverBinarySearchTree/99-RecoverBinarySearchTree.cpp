// Last updated: 8/20/2026, 9:15:27 PM
class Solution {
public:
    TreeNode *first = nullptr;
    TreeNode *second = nullptr;
    TreeNode *prev = nullptr;

    void help(TreeNode* root){
        if(!root) return;
        help(root->left);

        if(prev && prev->val > root->val){
            if(first) second = root;
            else {
                first = prev;
                second = root;
            }
        }
        prev = root;
        help(root->right);
    }

    void recoverTree(TreeNode* root) {
        help(root);
        swap(first->val, second->val);
    }
};