// Last updated: 6/25/2026, 11:13:04 PM
class Solution {
public:
    bool path(TreeNode* root, int a, string &s){
        if(!root) return false;
        if(root->val == a) return true;

        s.push_back('L');
        if(path(root->left, a, s)) return true;
        s.pop_back();

        s.push_back('R');
        if(path(root->right, a, s)) return true;
        s.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int s, int e) {
        string start = "", end = "";

        path(root, s, start);
        path(root, e, end);

        ranges::reverse(start);
        ranges::reverse(end);

        while(!start.empty() && !end.empty() && start.back() == end.back()){
            start.pop_back();
            end.pop_back();
        }
        ranges::reverse(end);
        return string(start.size(), 'U') + end;
    }
};