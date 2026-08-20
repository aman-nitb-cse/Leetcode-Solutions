// Last updated: 8/20/2026, 9:05:35 PM
class Codec {
public:
    string serialize(TreeNode* root) {
        if(!root) return "*";
        return to_string(root->val) + "[" + serialize(root->left) + "][" + serialize(root->right) + "]";
    }

    TreeNode* deserialize(string s) {
        if(s[0] == '*') return NULL;

        int pos = s.find('[');
        int val = stoi(s);
        auto root = new TreeNode(val);

        int x = pos + 1;

        int br = 1, i = x;
        for(; i < s.size(); i++){
            br += (s[i] == '[') - (s[i] == ']');
            if(br == 0) break;
        }

        // left subtree
        root->left = deserialize(s.substr(x, i - x));

        // right subtree starts after "]["
        int rightStart = i + 2;
        int rightLen = s.size() - rightStart - 1;

        root->right = deserialize(s.substr(rightStart, rightLen));

        return root;
    }
};