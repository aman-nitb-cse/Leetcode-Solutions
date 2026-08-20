// Last updated: 8/20/2026, 9:13:11 PM
class Node {
public:
    int val = -1, key = -1;
    Node* prev = NULL, *next = NULL;
    Node(int _key, int _val) : key(_key), val(_val) {}
    Node() {}
};

class LRUCache {
public:
    unordered_map<int, Node*> mp;
    Node* head = new Node();
    Node* tail = new Node();
    int k;
    LRUCache(int capacity) {
        head->next = tail;
        tail->prev = head;
        k = capacity;
    }

    void moveFront(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        insert(node);
    }

    void insert(Node* node){
        node->next = head->next;
        head->next = node;
        node->prev = head;
        node->next->prev = node;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        moveFront(mp[key]);
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            mp[key]->val = value;
            moveFront(mp[key]);
        }
        else if(k){
            mp[key] = new Node(key, value);
            insert(mp[key]);
            k--;
        }
        else {
            mp.erase(tail->prev->key);
            mp[key] = tail->prev;
            mp[key]->key = key;
            mp[key]->val = value;
            moveFront(mp[key]);
        }
    }
};