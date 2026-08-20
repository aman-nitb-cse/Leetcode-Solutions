// Last updated: 8/20/2026, 9:08:39 PM
class Solution {
public:
    int countRangeSum(vector<int>& nums, int s, int e) {
        multiset<long long> st = {0};
        long long pref = 0;
        int ans = 0;

        for(int &i : nums){
            pref += i;

            // count : x ∈ [pref - e, pref - s]

            ans += distance(st.lower_bound(pref - e), st.upper_bound(pref - s));
            st.insert(pref);
        }
        return ans;
    }
};