// Last updated: 6/25/2026, 11:19:56 PM
class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, -1), right(n, n);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] > nums[i]) st.pop();
            if(!st.empty()) left[i] = st.top();
            st.push(i);
        }

        st = stack<int>(); // clear

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            if(!st.empty()) right[i] = st.top();
            st.push(i);
        }

        long long ans = 0, mod = 1e9 + 7;

        for(int i = 0; i < n; i++){
            long long l = i - left[i];
            long long r = right[i] - i;

            ans = (ans + (l * r % mod) * nums[i]) % mod;
        }

        return ans;
    }
};