// Last updated: 8/20/2026, 9:11:21 PM
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> st(nums.begin(), nums.end());
        return *prev(st.end(), k);
    }
};