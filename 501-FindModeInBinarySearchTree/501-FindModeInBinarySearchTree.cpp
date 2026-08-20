// Last updated: 8/20/2026, 9:04:08 PM
class Solution {
public:
    unordered_map<int, int> hash;
    void Hash(TreeNode* root){
        if(!root) return;
        hash[root->val]++;
        Hash(root->left);
        Hash(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        Hash(root);
        vector<int> ans;
        int max_frq = 0;
        for(auto &i : hash){
            if(max_frq == i.second) ans.push_back(i.first);
            else if(max_frq < i.second){
                ans.clear();
                ans.push_back(i.first);
                max_frq = i.second;
            }
        }
        return ans;
    }
};