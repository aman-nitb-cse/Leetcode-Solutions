// Last updated: 6/25/2026, 11:11:56 PM
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
    unordered_map <TreeNode*, TreeNode*> Root;
    TreeNode* node = nullptr;
    int start;
    unordered_set <TreeNode*> st;

    void dfs(TreeNode* root){
        if(!root) return;
        if(root->val == start) node = root;
        if(root->left) Root[root->left] = root;
        if(root->right) Root[root->right] = root;
        dfs(root->left);
        dfs(root->right);
    }

    int Max(int a, int b, int c){
        return max(a, max(b, c));
    }

    int solve(TreeNode* root, int time = 0){
        if(!root || st.find(root) != st.end()) return time - 1;
        st.insert(root);
        time++;
        return Max(solve(root->left, time), solve(root->right, time), solve(Root[root], time));
    }

    int amountOfTime(TreeNode* root, int _start) {
        start = _start;
        dfs(root);
        return solve(node);
    }
};