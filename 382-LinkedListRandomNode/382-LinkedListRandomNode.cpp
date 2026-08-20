// Last updated: 8/20/2026, 9:07:15 PM
class Solution {
public:
    vector<int> val;
    int n;
    Solution(ListNode* head) {
        while(head){
            val.push_back(head->val);
            head = head->next;
        }
        n = val.size();
        srand(time(0));
    }
    
    int getRandom() {
        return val[rand() % n];
    }
};