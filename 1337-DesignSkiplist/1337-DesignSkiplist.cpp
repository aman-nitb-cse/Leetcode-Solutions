// Last updated: 6/25/2026, 11:17:37 PM
class Skiplist {
public:
    unordered_multiset<int> st;
    Skiplist() {}
    
    bool search(int target) {
        return st.count(target);
    }
    
    void add(int num) {
        st.insert(num);
    }
    
    bool erase(int num) {
        if(!st.count(num)) return false;

        st.erase(st.find(num));

        return true;
    }
};