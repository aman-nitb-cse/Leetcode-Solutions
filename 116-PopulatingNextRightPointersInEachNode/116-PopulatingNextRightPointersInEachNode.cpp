// Last updated: 8/20/2026, 9:14:39 PM
class Solution {
public:
    Node* connect(Node* root) {
        if(root){
            auto A = root->left, B = root->right;
            while(A){
                A->next = B;
                A = A->right;
                B = B->left;
            }
            connect(root->left);
            connect(root->right);
        }
        return root;
    }
};