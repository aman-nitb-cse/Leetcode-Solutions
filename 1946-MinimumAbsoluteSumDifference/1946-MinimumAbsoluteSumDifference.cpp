// Last updated: 8/20/2026, 8:49:31 PM
class Solution {
public:
    using ll = long long;
    const int mod = 1e9 + 7;
    int minAbsoluteSumDiff(vector<int>& a, vector<int>& b) {
        ll sum = 0;

        int n = a.size();
        for(int i = 0; i < n; i++){
            sum += abs(a[i] - b[i]);
        }

        set<int> st(a.begin(), a.end());

        ll min_sum = sum;

        for(int i = 0; i < n; i++){
            ll nsum = sum - abs(a[i] - b[i]);

            auto it = st.lower_bound(b[i]);

            if(it != st.end()) min_sum = min(min_sum, nsum + abs(*it - b[i]));
            if(it != st.begin()) min_sum = min(min_sum, nsum + abs(*prev(it) - b[i]));
        }
        return min_sum % mod;
    }
};