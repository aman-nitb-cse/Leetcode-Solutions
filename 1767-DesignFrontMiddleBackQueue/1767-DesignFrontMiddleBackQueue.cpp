// Last updated: 6/25/2026, 11:15:27 PM
class Node {
public:
    Node *next = NULL, *prev = NULL;
    int val;
    Node(int x) : val(x) {}
};

class FrontMiddleBackQueue {
public:
    Node *head, *tail, *mid;
    int size = 0;
    FrontMiddleBackQueue() {}
    
    void pushFront(int val) {
        auto node = new Node(val);

        if(!size) head = tail = mid = node;
        else {
            node->next = head;
            head->prev = node;
            head = node;

            if(size & 1) mid = mid->prev;
        }
        size++;
    }
    
    void pushMiddle(int val) {
        auto node = new Node(val);

        if(!size) head = tail = node;
        else if(size == 1){
            node->next = mid;
            mid->prev = node;
            head = node;
        }
        else if(size & 1){ // before mid
            auto left = mid->prev, right = mid;

            left->next = right->prev = node;
            node->prev = left;
            node->next = right;
        }
        else { // after mid
            auto left = mid, right = mid->next;

            left->next = right->prev = node;
            node->prev = left;
            node->next = right;
        }
        mid = node;
        size++;
    }
    
    void pushBack(int val) {
        auto node = new Node(val);

        if(!size) head = tail = mid = node;
        else {
            node->prev = tail;
            tail->next = node;
            tail = node;

            if(!(size & 1)) mid = mid->next;
        }

        size++;
    }
    
    int popFront() {
        if(!size) return -1;

        int x = head->val;

        if(size == 1) head = tail = mid = NULL;
        else {
            head = head->next;
            head->prev = NULL;

            if(!(size & 1)) mid = mid->next;
        }

        size--;

        return x;
    }
    
    int popMiddle() {
        if(!size) return -1;

        int x = mid->val;

        if(size == 1)  head = tail = mid = NULL;
        else if(size == 2){
            head = mid = mid->next;
            head->prev = NULL;
        }
        else {
            auto nmid = (size & 1) ? mid->prev : mid->next;

            mid->next->prev = mid->prev;
            mid->prev->next = mid->next; 

            mid = nmid;
        }

        size--;

        return x;
    }
    
    int popBack() {
        if(!size) return -1;

        int x = tail->val;

        if(size == 1) head = tail = mid = NULL;
        else {
            tail = tail->prev;
            tail->next = NULL;

            if(size & 1) mid = mid->prev;
        }

        size--;

        return x;
    }
};