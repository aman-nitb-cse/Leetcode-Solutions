// Last updated: 6/24/2026, 3:30:57 AM
class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int,vector<int>> index;

        for(int i = 0; i < n; i++){
            index[nums[i]].push_back(i);
        }

        vector<int> NGE(n, n);

        stack<int> st;

        for(int i = n - 1; i >= 0; i--){

            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();

            if(!st.empty()) NGE[i] = st.top();

            st.push(i);
        }

        long long ans = 0;

        for(int i = 0; i < n; i++){

            ans += ranges::lower_bound(index[nums[i]], NGE[i]) - ranges::lower_bound(index[nums[i]], i);
        }

        return ans;
    }
};