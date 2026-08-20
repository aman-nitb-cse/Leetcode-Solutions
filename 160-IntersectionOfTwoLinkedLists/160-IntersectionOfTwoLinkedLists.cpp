// Last updated: 8/20/2026, 9:12:45 PM
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *A, ListNode *B) {
        unordered_set<ListNode*> st;

        for(auto temp = A; temp; temp = temp->next) st.insert(temp);
        for(auto temp = B; temp; temp = temp->next){
            if(st.find(temp) != st.end()) return temp;
        }
        return nullptr;
    }
};