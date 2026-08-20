// Last updated: 8/20/2026, 9:11:13 PM
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& v, int k) {
        if(!k) return false;
        unordered_set <int> st;
        for(int i = 0; i < v.size(); i++){
            if(st.find(v[i]) != st.end()) return true;
            if(i >= k) st.erase(v[i - k]);
            st.insert(v[i]);
        }
        return false;
    }
};