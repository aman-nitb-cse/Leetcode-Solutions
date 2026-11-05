// Last updated: 11/6/2026, 5:07:25 AM
class Solution {
public:
    vector<int> replaceElements(vector<int>& v) {
        set<int> st = {-1};
        for(int i = v.size() - 1; i >= 0; i--){
            int temp = v[i];
            v[i] = *st.rbegin();
            st.insert(temp);
        }
        return v;
    }
};