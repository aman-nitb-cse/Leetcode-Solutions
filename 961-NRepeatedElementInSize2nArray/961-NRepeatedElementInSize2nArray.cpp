// Last updated: 11/6/2026, 5:10:27 AM
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