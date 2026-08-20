// Last updated: 8/20/2026, 9:02:02 PM
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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<double> ans;
        double count = 0;
        double sum = 0;
        while(!q.empty()){
            auto node = q.front(); q.pop();

            if(node){
                count++;
                sum += node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            else {
                ans.push_back(sum / count);
                sum = count = 0;
                if(!q.empty()) q.push(NULL);
            }
        }
        return ans;
    }
};