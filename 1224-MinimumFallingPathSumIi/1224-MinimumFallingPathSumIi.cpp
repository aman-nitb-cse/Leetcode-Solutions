// Last updated: 6/25/2026, 11:18:13 PM
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