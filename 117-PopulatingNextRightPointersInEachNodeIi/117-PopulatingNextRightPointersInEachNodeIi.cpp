// Last updated: 8/20/2026, 9:14:35 PM
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            auto node = q.front(); q.pop();
            if(!node){
                if(!q.empty()) q.push(NULL);
            }
            else {
                node->next = q.front();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return root;
    }
};