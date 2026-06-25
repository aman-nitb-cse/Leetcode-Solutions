// Last updated: 6/25/2026, 11:20:27 PM
class Solution {
public:
    unordered_map <TreeNode*, TreeNode*> Root;
    int k;
    unordered_set <TreeNode*> st;
    vector<int> ans;

    void dfs(TreeNode* root){
        if(!root) return;
        if(root->left) Root[root->left] = root;
        if(root->right) Root[root->right] = root;
        dfs(root->left);
        dfs(root->right);
    }

    void solve(TreeNode* root, int d = 0){
        if(!root || st.find(root) != st.end()) return;
        st.insert(root);
        if(d == k){
            ans.push_back(root->val);
            return;
        }
        d++;
        solve(root->left, d);
        solve(root->right, d);
        solve(Root[root], d);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int _k) {
        k = _k;
        dfs(root);
        solve(target);
        return ans;
    }
};