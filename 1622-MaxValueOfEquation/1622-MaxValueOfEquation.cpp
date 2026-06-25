// Last updated: 6/25/2026, 11:15:56 PM
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& nums, int k) {
        multiset<int> st;
        
        int ans = INT_MIN;

        for(int l = 0, r = 0; r < nums.size(); r++){
            while(nums[l][0] < nums[r][0] - k && l < r) {
                st.erase(st.find(nums[l][1] - nums[l][0]));
                l++;
            }

            if(!st.empty()) ans = max(ans, *st.rbegin() + nums[r][1] + nums[r][0]);

            st.insert(nums[r][1] - nums[r][0]);
        }

        return ans;
    }
};

// (yj + xj) + (yi - xi)
// xi >= xj - k