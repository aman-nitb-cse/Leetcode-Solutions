// Last updated: 6/25/2026, 11:10:54 PM
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st(banned.begin(), banned.end());
        int count = 0;
        for(int i = 1; i <= n; i++){ // rule 1
            if(st.find(i) != st.end()) continue; // rule 3
            maxSum -= i;
            if(maxSum < 0) return count;
            count++;
        }
        return count;
    }
};