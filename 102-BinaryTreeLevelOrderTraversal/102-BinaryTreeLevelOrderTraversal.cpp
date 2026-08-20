// Last updated: 8/20/2026, 9:15:15 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
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
                else return ans;
            }
            else {
                v.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return ans;
    }
};