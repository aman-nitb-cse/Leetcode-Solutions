// Last updated: 6/25/2026, 11:12:37 PM
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
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        unordered_map<int, TreeNode*> tree;
        unordered_set<int> parent, child;
        for(int i = 0; i < d.size(); i++){

            parent.insert(d[i][0]);
            child.insert(d[i][1]);

            if(!tree.count(d[i][0])) tree[d[i][0]] = new TreeNode(d[i][0]);
            if(!tree.count(d[i][1])) tree[d[i][1]] = new TreeNode(d[i][1]);
            
            if(d[i][2] == 1) tree[d[i][0]]->left = tree[d[i][1]];
            else tree[d[i][0]]->right = tree[d[i][1]];
        }

        for(int i : parent){
            if(!child.count(i)) return tree[i];
        }

        return nullptr;
    }
};