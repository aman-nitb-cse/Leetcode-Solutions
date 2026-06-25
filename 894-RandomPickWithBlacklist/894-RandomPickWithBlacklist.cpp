// Last updated: 6/25/2026, 11:20:25 PM
class Solution {
public:
    int n, rem, extra_size;
    unordered_set<int> st;
    vector<int> extra;
    Solution(int _n, vector<int>& bl) {
        st.insert(bl.begin(), bl.end());
        n = _n;
        rem = n - st.size();

        for(int i = rem; i < n; i++){
            if(!st.count(i)) extra.push_back(i);
        }
        extra_size = extra.size();
        srand(time(0));
    }
    
    int pick() {
        int x = rand() % rem;
        if(!st.count(x)) return x;
        x %= extra_size;
        return extra[x];
    }
};