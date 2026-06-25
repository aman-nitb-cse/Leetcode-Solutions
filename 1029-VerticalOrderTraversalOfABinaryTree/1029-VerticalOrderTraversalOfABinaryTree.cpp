// Last updated: 6/25/2026, 11:19:13 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void verticalTraversalHelp(TreeNode* root, vector<vector<int>>& v, int r = 0, int c = 0) { // v : r c data
        if (!root) return;
        v.push_back({c, r, root->val});
        if (root->left) verticalTraversalHelp(root->left, v, r + 1, c - 1);
        if (root->right) verticalTraversalHelp(root->right, v, r + 1, c + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> v;
        verticalTraversalHelp(root, v);
        sort(v.begin(), v.end());
        vector <int> temp;
        vector <vector<int>> ans;
        for(int i = 0; i < v.size(); i++){
            if(i and v[i][0] != v[i - 1][0]){
                if(v.size()) ans.push_back(temp);
                temp.clear();
            }
            temp.push_back(v[i][2]);
        }
        if(!temp.empty()) ans.push_back(temp);
        return ans;
    }
};