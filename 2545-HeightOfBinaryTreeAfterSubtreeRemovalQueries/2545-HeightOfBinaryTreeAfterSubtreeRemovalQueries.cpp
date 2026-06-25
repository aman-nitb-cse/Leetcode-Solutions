// Last updated: 6/25/2026, 11:11:25 PM
class Solution {
public:
    // L[u] = index of leftmost leaf in subtree of u
    vector<int> L;

    // R[u] = index of rightmost leaf in subtree of u
    vector<int> R;

    // D[u] = depth of node u from root
    vector<int> D;

    // pref[i] = maximum leaf depth among leaf indices [0...i]
    vector<int> pref;

    // suff[i] = maximum leaf depth among leaf indices [i...last]
    vector<int> suff;

    int leafIdx = 0;

    int countNodes(TreeNode* root){
        if(!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    void dfs(TreeNode* root, int dep){

        if(!root) return;

        int u = root->val;

        D[u] = dep;

        if(!root->left && !root->right){

            L[u] = leafIdx;
            R[u] = leafIdx;

            pref.push_back(dep);

            leafIdx++;

            return;
        }

        if(root->left) dfs(root->left, dep + 1);
        if(root->right) dfs(root->right, dep + 1);

        if(root->left && root->right){

            L[u] = L[root->left->val];
            R[u] = R[root->right->val];
        }
        else if(root->left){

            L[u] = L[root->left->val];
            R[u] = R[root->left->val];
        }
        else{

            L[u] = L[root->right->val];
            R[u] = R[root->right->val];
        }
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {

        int n = countNodes(root);

        L.resize(n + 1);
        R.resize(n + 1);
        D.resize(n + 1);

        dfs(root, 0);

        int m = pref.size();

        suff = pref;

        for(int i = 1; i < m; i++){
            pref[i] = max(pref[i - 1], pref[i]);
        }

        for(int i = m - 2; i >= 0; i--){
            suff[i] = max(suff[i], suff[i + 1]);
        }

        vector<int> ans;

        for(int u : queries){

            int cur = -1;

            int l = L[u];
            int r = R[u];

            if(l > 0) cur = max(cur, pref[l - 1]);
            if(r + 1 < m) cur = max(cur, suff[r + 1]);

            cur = max(cur, D[u] - 1);

            ans.push_back(cur);
        }

        return ans;
    }
};