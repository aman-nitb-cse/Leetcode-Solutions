// Last updated: 6/25/2026, 11:18:57 PM
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& pre, int s = 0, int e = -1) {
        if(e == -1) e = pre.size() - 1;
        if(s > e) return nullptr;
        for(int i = s; i <= e; i++){
            if(pre[i] > pre[s]) 
                return new TreeNode(pre[s], bstFromPreorder(pre, s + 1, i - 1), bstFromPreorder(pre, i, e));
        }
        return new TreeNode(pre[s], bstFromPreorder(pre, s + 1, e), nullptr);
    }
};