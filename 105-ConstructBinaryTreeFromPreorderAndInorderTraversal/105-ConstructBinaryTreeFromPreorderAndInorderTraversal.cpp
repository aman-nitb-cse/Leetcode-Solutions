// Last updated: 8/20/2026, 9:15:11 PM
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
    TreeNode* buildTree(vector<int>& pre, vector<int>& in, int s1 = 0, int e1 = -1, int s2 = 0, int e2 = -1) {
        if(e1 == -1){
            e1 = pre.size() - 1;
            e2 = in.size() - 1;
        }
        if(s1 > e1 || s2 > e2) return nullptr;
        int node_index = 0;
        for(int i = s2; i <= e2; i++){
            if(in[i] == pre[s1]){
                node_index = i;
                break;
            }
        }
        int leftSize = node_index - s2;
        return new TreeNode(in[node_index], buildTree(pre, in, s1 + 1, s1 + leftSize, s2, node_index - 1), buildTree(pre, in, s1 + 1 + leftSize, e1, node_index + 1, e2));
    }
};