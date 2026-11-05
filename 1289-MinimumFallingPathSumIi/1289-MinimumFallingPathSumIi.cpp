// Last updated: 11/6/2026, 5:07:30 AM
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& m) {
        multiset<int> st;
        int n = m.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n && i; j++){
                st.erase(st.find(m[i - 1][j]));
                m[i][j] += *st.begin();
                st.insert(m[i - 1][j]);
            }
            st.clear();
            for(int j = 0; j < n; j++){
                st.insert(m[i][j]);
            }
        }
        return *st.begin();
    }
};