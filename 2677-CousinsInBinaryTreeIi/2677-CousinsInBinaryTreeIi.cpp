// Last updated: 6/25/2026, 11:10:48 PM
class Pair {
public:
    TreeNode* parent;
    int sum;
    Pair(TreeNode* p, int s) : parent(p), sum(s) {}
};

class Solution {
public:
    vector<vector<Pair>> v;

    void store(TreeNode* root, int l = 0){
        if(!root) return;
        if(v.size() <= l) v.resize(l + 1);
        int _sum = 0;
        if(root->left) _sum += root->left->val;
        if(root->right) _sum += root->right->val;

        v[l].push_back({root, _sum});
        store(root->left, l + 1);
        store(root->right, l + 1);
    }

    void solve(TreeNode* root, int l = 0){
        if(!root) return;
        int _sum = 0;
        for(int i = 0; i < v[l].size(); i++){
            if(v[l][i].parent != root) _sum += v[l][i].sum;
        }

        if(root->left) root->left->val = _sum;
        if(root->right) root->right->val = _sum;
        solve(root->left, l + 1);
        solve(root->right, l + 1);
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        store(root);
        solve(root);
        root->val = 0;
        return root;
    }
};