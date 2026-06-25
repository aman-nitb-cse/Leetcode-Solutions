// Last updated: 6/25/2026, 11:19:36 PM
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> st;
        for(int &i : nums){
            if(st.find(i) != st.end()) return i;
            st.insert(i);
        }
        return 0;
    }
};