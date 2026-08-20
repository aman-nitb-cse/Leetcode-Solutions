// Last updated: 8/20/2026, 9:11:15 PM
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        return st.size() != nums.size();
    }
};