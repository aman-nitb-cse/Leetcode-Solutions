// Last updated: 8/20/2026, 9:15:03 PM
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue <TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector <int> v;
        while(!q.empty()){
            TreeNode* temp = q.front(); q.pop();
            if(!temp){
                ans.push_back(v); 
                v.clear();
                if(!q.empty()) q.push(NULL);
            }
            else {
                v.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        ranges::reverse(ans);
        return ans;
    }
};