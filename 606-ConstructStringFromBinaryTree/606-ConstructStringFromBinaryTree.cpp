// Last updated: 8/20/2026, 9:02:24 PM
class Solution {
public:
    string tree2str(TreeNode* root) {
        if(!root) return "";
        
        string left = tree2str(root->left);
        string node = to_string(root->val);
        string right = tree2str(root->right);

        if(left.empty() && right.empty()) return node;
        if(left.empty() && !right.empty()) return node + "()(" + right + ')';
        if(!left.empty() && right.empty()) return node + '(' + left + ')';
        if(!left.empty() && !right.empty()) return node + '(' + left + ")(" + right + ')';
        return "";
    }
};