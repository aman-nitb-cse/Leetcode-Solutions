// Last updated: 6/25/2026, 11:20:44 PM
class Node {
public:
    Node* prev = NULL, *next = NULL;
    int val;
    Node(int x){
        val = x;
    }
};

class MyCircularDeque {
public:
    int k, size = 0;
    Node* head = NULL, *tail = NULL;
    MyCircularDeque(int _k) : k(_k) {}
    
    bool insertFront(int value) {
        if(size == k) return false;

        auto node = new Node(value);

        if(!size) head = tail = node;
        else {
            node->next = head;
            head->prev = node;
            head = node;
        }

        size++;

        return true;
    }
    
    bool insertLast(int value) {
        if(size == k) return false;

        auto node = new Node(value);

        if(!size) head = tail = node;
        else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }

        size++;

        return true;
    }
    
    bool deleteFront() {
        if(!size) return false;

        if(size == 1) head = tail = NULL;
        else {
            head = head->next;
            head->prev = NULL;
        }

        size--;

        return true;
    }
    
    bool deleteLast() {
        if(!size) return false;

        if(size == 1) head = tail = NULL;
        else {
            tail = tail->prev;
            tail->next = NULL;
        }

        size--;

        return true;
    }
    
    int getFront() {
        if(!size) return -1;

        return head->val;
    }
    
    int getRear() {
        if(!size) return -1;

        return tail->val;
    }
    
    bool isEmpty() {
        return !size;
    }
    
    bool isFull() {
        return size == k;
    }
};