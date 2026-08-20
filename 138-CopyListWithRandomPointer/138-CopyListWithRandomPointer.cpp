// Last updated: 8/20/2026, 9:13:36 PM
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> copy = {{nullptr, nullptr}};

        
        for(auto it = head; it; it = it->next){
            copy[it] = new Node(it->val);
        }

        for(auto it = head; it; it = it->next){
            copy[it]->next = copy[it->next];
            copy[it]->random = copy[it->random];
        }
        return copy[head];
    }
};