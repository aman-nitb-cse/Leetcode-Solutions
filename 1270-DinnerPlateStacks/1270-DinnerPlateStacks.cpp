// Last updated: 8/20/2026, 8:54:45 PM
class DinnerPlates {
public:
    set<int> st; // less capacity
    set<int> filled; // store not empty indexes
    int k;
    vector<vector<int>> v;
    DinnerPlates(int c) {
        k = c;
        v.resize(100001);

        for(int i = 0; i < 100001; i++) st.insert(i);
    }
    
    void push(int val) {
        int i = *st.begin();

        v[i].push_back(val);

        filled.insert(i);

        if(v[i].size() == k) st.erase(i);
    }
    
    int pop() {
        return filled.empty() ? -1 : popAtStack(*filled.rbegin());
    }
    
    int popAtStack(int i) {

        if(v[i].empty()) return -1;

        int val = v[i].back();

        v[i].pop_back();

        st.insert(i);

        if(v[i].empty()) filled.erase(i);

        return val;
    }
};