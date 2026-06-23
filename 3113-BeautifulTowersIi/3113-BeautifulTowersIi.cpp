// Last updated: 6/24/2026, 3:31:51 AM
class Solution {
public:
    using ll = long long;

    long long maximumSumOfHeights(vector<int>& H) {

        int n = H.size();

        vector<ll> pref(n), suf(n);
        vector<int> ple(n), nle(n);

        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && H[st.top()] > H[i])
                st.pop();

            ple[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && H[st.top()] >= H[i])
                st.pop();

            nle[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        for(int i = 0; i < n; i++){
            int prev = ple[i];

            if(prev == -1)
                pref[i] = 1LL * H[i] * (i + 1);
            else
                pref[i] = 1LL * H[i] * (i - prev) + pref[prev];
        }

        for(int i = n - 1; i >= 0; i--){
            int next = nle[i];

            if(next == n)
                suf[i] = 1LL * H[i] * (n - i);
            else
                suf[i] = 1LL * H[i] * (next - i) + suf[next];
        }

        ll ans = 0;

        for(int i = 0; i < n; i++){
            ans = max(ans, pref[i] + suf[i] - H[i]);
        }

        return ans;
    }
};