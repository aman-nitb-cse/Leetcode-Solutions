// Last updated: 8/20/2026, 9:05:03 PM
class Node{
public:
    int val, key, count;
    Node *prev, *next;
    Node(int k, int v){
        key = k;
        val = v;
        count = 0;
        prev = next = NULL;
    }
};

class LFUCache {
public:
    unordered_map<int,Node*> mp;
    map<int, pair<Node*,Node*>> LL;
    int c;

    LFUCache(int capacity) {
        c = capacity;
    }

    void remove(Node* node){
        node->next->prev = node->prev;
        node->prev->next = node->next;

        auto& [head, tail] = LL[node->count];
        if(head->next == tail) LL.erase(node->count);
    }

    void insert(Node* node){
        node->count++;

        if(!LL.count(node->count)){
            auto head = new Node(-1, -1);
            auto tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
            LL[node->count] = {head, tail};
        }

        auto& [head, tail] = LL[node->count];

        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    
    int get(int key) {
        if(mp.count(key)){
            auto node = mp[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(c == 0) return;

        if(mp.count(key)){
            auto node = mp[key];
            remove(node);
            node->val = value;
            insert(node);
        }
        else{
            if(mp.size() == c){
                auto& [head, tail] = LL.begin()->second;
                auto node = tail->prev;

                remove(node);
                mp.erase(node->key);
                delete node;
            }

            auto node = new Node(key, value);
            insert(node);
            mp[key] = node;
        }
    }
};