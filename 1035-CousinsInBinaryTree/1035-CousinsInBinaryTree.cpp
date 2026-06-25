// Last updated: 6/25/2026, 11:19:04 PM
class Solution {
public:
    int _x, _y, x, y, lx, ly, px, py;
    int depth(TreeNode* root, TreeNode* p = nullptr, int l = 0){
        if(!root) return 0;
        if(root->val == x) {
            _x = 1 + max(depth(root->left, root, l + 1), depth(root->right, root, l + 1));
            lx = l;
            px = p->val;
            return _x;
        }
        if(root->val == y) {
            _y = 1 + max(depth(root->left, root, l + 1), depth(root->right, root, l + 1));
            ly = l;
            py = p->val;
            return _y;
        }
        return 1 + max(depth(root->left, root, l + 1), depth(root->right, root, l + 1));
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(x == root->val || y == root->val) return false;
        this->x = x;
        this->y = y;
        depth(root);
        return (lx == ly) && (px != py);
    }
};