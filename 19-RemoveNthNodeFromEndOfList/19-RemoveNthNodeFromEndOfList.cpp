// Last updated: 8/20/2026, 9:19:37 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        for(ListNode* i = head;  i; i = i->next) size++;

        if(n > size or n < 1) return head;
        int t = size - n - 1;
        ListNode* temp = head;
        if(t == -1){
            head = head->next;
            delete temp;
            return head;
        }
        while(t--){
            temp = temp->next;
        }

        ListNode* deletingNode = temp->next;
        temp->next = temp->next->next;
        delete deletingNode;

        return head;
    }
};