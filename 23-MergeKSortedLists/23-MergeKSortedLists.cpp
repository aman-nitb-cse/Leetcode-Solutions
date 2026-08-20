// Last updated: 8/20/2026, 9:19:29 PM
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& list) {
        priority_queue<pair<int, ListNode*>> pq;
        for(auto &i : list){
            if(i) pq.push({-i->val, i});
        }
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(!pq.empty()){
            auto temp = pq.top().second; pq.pop();
            if(temp->next) pq.push({-temp->next->val, temp->next});
            if(head) {
                tail->next = temp;
                tail = tail->next;
            }
            else head = tail = temp;
        }
        return head;
    }
};