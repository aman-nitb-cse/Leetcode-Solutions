// Last updated: 6/25/2026, 11:11:19 PM
class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        set <float> st;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i <= n / 2; i++){
            st.insert((nums[i] + nums[n - i - 1]) / 2.0);
        }
        return st.size();
    }
};