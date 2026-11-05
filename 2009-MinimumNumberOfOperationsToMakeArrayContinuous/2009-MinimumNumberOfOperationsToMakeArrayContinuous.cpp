// Last updated: 11/6/2026, 4:56:03 AM
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        set<int> st(nums.begin(), nums.end());

        nums.assign(st.begin(), st.end());
        
        int mn = nums.front();
        int mx = nums.back();

        int ans = n;

        for (int &i : nums) {
            int s = i, e = i + n - 1;

            auto left = ranges::lower_bound(nums, s);
            auto right = ranges::upper_bound(nums, e);
            int inside = right - left;

            ans = min(ans, n - inside);
        }

        return ans;
    }
};
