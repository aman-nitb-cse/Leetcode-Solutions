// Last updated: 8/20/2026, 9:12:30 PM
class BSTIterator {
public:
    vector<int> v;
    int idx = 0;
    BSTIterator(TreeNode* root) {
        v = dfs(root);
    }

    vector<int> dfs(TreeNode* root){
        if(!root) return {};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        left.push_back(root->val);
        for(auto &i : right) left.push_back(i);

        return left;
    }
    
    int next() {
        return v[idx++];
    }
    
    bool hasNext() {
        return idx < v.size();
    }
};