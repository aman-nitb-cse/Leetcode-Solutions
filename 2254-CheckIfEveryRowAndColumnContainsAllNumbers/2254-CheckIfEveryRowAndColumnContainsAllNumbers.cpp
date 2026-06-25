// Last updated: 6/25/2026, 11:12:51 PM
class Solution {
public:
    bool checkValid(vector<vector<int>>& a) {
        int n = a.size();
        unordered_set <int> st;
        for(int i = 1; i <= n; i++) st.insert(i);

        int sum = n * (n + 1) / 2;
        for(int i = 0; i < n; i++){
            unordered_set <int> r, c;
            for(int j = 0; j < n; j++){
                r.insert(a[i][j]);
                c.insert(a[j][i]);
            }
            if(r != st or c != st) return false;
        }
        return true;
    }
};