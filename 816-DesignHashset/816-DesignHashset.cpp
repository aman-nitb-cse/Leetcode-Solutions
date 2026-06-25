// Last updated: 6/25/2026, 11:20:57 PM
class MyHashSet {
    unordered_set <int> hash;
public:
    void add(int key) {
        hash.insert(key);
    }
    
    void remove(int key) {
        hash.erase(key);
    }
    
    bool contains(int key) {
        return hash.find(key) != hash.end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */