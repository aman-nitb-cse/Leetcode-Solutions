// Last updated: 6/25/2026, 11:17:55 PM
class Solution {
public:
    vector<int> v;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }

    TreeNode* buildTree(int s, int e){
        if(s > e) return nullptr;
        int mid = (s + e) / 2;
        return new TreeNode(v[mid], buildTree(s, mid - 1), buildTree(mid + 1, e));
    }

    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return buildTree(0, v.size() - 1);
    }
};