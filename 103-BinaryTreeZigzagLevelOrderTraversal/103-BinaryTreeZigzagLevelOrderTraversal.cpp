// Last updated: 8/20/2026, 9:15:18 PM
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector <int> v;
        if(!root) return ans;
        queue <TreeNode*> q;
        q.push(root);
        q.push(NULL);
        bool flag = false;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(!temp){
                if(flag) reverse(v.begin(), v.end());
                ans.push_back(v);
                v.clear();
                flag = !flag;
                if(!q.empty()) q.push(NULL);
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