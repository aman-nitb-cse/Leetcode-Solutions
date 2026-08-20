// Last updated: 8/20/2026, 9:01:35 PM
class Solution {
public:
    unordered_map<string,pair<int,TreeNode*>> freq;
    string dfs(TreeNode* root){
        if(!root) return "*";

        string left = dfs(root->left);
        string right = dfs(root->right);

        string s = to_string(root->val) + "#" + left + "#" + right + "#";

        freq[s].first++;
        freq[s].second = root;

        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        vector<TreeNode*> ans;

        for(auto &[s, p] : freq){
            if(p.first > 1) ans.push_back(p.second);
        }
        return ans;
    }
};