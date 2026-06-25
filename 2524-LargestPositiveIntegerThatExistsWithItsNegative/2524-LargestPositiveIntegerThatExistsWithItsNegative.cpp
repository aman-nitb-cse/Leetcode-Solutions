// Last updated: 6/25/2026, 11:11:35 PM
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        set <int> st(nums.begin(), nums.end());
        for(auto i = st.rbegin(); i != st.rend(); i++){
            if(st.find(-*i) != st.end()) return *i;
        }
        return -1;
    }
};