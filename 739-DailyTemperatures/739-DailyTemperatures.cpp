// Last updated: 6/25/2026, 11:21:47 PM
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        stack<pair<int,int>> st;
        st.push({101, 0});
        for(int i = nums.size() - 1; i >= 0; i--){
            while(st.top().first <= nums[i]) st.pop();
            int val = nums[i];
            int next_day = st.top().second;

            nums[i] = max(0, next_day - i);
            st.push({val, i});
        }
        return nums;
    }
};