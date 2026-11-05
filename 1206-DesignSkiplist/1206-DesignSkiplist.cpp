// Last updated: 11/6/2026, 5:06:06 AM
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