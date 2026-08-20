// Last updated: 8/20/2026, 9:15:04 PM
class Solution {
public:
    TreeNode* buildTree(vector<int>& in, vector<int>& post, int s1 = 0, int e1 = -10, int s2 = 0, int e2 = -10) {
        if(e1 == -10){
            e1 = in.size() - 1;
            e2 = post.size() - 1;
        }
        if(s1 > e1 || s2 > e2) return nullptr;
        int node = s1;
        while(node <= e1 && in[node] != post[e2]) node++;

        int leftSize = node - s1;
        return new TreeNode(
            in[node],
            buildTree(in, post, s1, node - 1, s2, s2 + leftSize - 1),
            buildTree(in, post, node + 1, e1, s2 + leftSize, e2 - 1)
        );
    }
};