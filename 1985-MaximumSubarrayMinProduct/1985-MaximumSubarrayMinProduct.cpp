// Last updated: 6/25/2026, 11:14:23 PM
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, -1), right(n, n);

        stack<pair<int,int>> st; // {val, index}
        // forword
        for(int i = 0; i < n; i++){
            while(!st.empty() && st.top().first > nums[i]) st.pop();

            if(!st.empty()) left[i] = st.top().second;

            st.push({nums[i], i});
        }

        st = stack<pair<int,int>> ();

        // backword
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && st.top().first >= nums[i]) st.pop();

            if(!st.empty()) right[i] = st.top().second;

            st.push({nums[i], i});
        }

        // prefix sum 
        vector<long long> pref(n);
        for(int i = 0; i < n; i++) {
            pref[i] = nums[i];
            if(i) pref[i] += pref[i - 1];
        }

        long long ans = 0;
        for(int i = 0; i < n; i++){
            int l = left[i], r = right[i];

            long long sum = pref[r - 1];
            if(l != -1) sum -= pref[l];

            ans = max(ans, sum * nums[i]);
        }

        for(int &i : left) cout << i << ' ';

        return ans % 1000000007;
    }
};