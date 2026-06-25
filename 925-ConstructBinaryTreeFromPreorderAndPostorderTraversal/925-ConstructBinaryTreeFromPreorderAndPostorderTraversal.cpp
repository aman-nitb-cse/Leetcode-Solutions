// Last updated: 6/25/2026, 11:20:07 PM
class Solution {
public:
    unordered_map<int,int> pos;

    TreeNode* f(vector<int>& pre, vector<int>& post, int i, int j, int n){
        if(n == 0) return NULL;

        auto root = new TreeNode(pre[i]);
        if(n == 1) return root;

        int k = pos[pre[i + 1]] - j + 1;

        root->left = f(pre, post, i + 1, j, k);
        root->right = f(pre, post, i + 1 + k, j + k, n - k - 1);

        return root; 
    }

    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        for(int i = 0; i < post.size(); i++) pos[post[i]] = i;
        return f(pre, post, 0, 0, pre.size());
    }
};