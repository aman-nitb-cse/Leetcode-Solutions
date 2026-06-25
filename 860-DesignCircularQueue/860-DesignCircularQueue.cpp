// Last updated: 6/25/2026, 11:20:43 PM
class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class MyCircularQueue {
public:
    Node *head, *tail;
    int k, size;
    MyCircularQueue(int k) : k(k), size(0), head(nullptr), tail(nullptr) {}
    
    bool enQueue(int value) {
        if(k == size) return false;
        if(!head) tail = head = new Node(value);
        else {
            tail->next = new Node(value);
            tail = tail->next;
        }
        size++;
        return true;
    }
    
    bool deQueue() {
        if(!head) return false;
        Node* temp = head;
        head = head->next;
        if(!head) tail = nullptr;
        delete temp;
        size--;
        return true;
    }
    
    int Front() {
        if(!head) return -1;
        return head->data;
    }
    
    int Rear() {
        if(!head) return -1;
        return tail->data;
    }
    
    bool isEmpty() {
        return !head;
    }
    
    bool isFull() {
        return k == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */