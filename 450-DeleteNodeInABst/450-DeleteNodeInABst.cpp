// Last updated: 8/20/2026, 9:05:33 PM
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(key < root->val) root->left =  deleteNode(root->left, key);
        else if(key > root->val) root->right =  deleteNode(root->right, key);
        // found
        else {
            TreeNode* right = root->right;
            root = root->left;
            TreeNode* temp = root;
            if(!temp) return right;
            while(temp->right) temp = temp->right;
            temp->right = right;
            return root;
        }
        return root;
    }
};