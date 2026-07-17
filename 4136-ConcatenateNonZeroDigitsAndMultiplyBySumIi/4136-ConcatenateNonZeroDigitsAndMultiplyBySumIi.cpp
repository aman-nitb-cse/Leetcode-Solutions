// Last updated: 7/18/2026, 12:21:39 AM
#define F(i, a, b) for(int i = a; i <= b; i++)
#define ll long long

class Solution {
public:
    const int mod = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        
        vector<int> cnt(n), sum(n);
        vector<ll> pref(n);

        // cnt : store count of non-zero chars
        // sum : digit prefix sum
        // pref : store prefix number

        F(i, 0, n - 1){
            cnt[i] = (s[i] != '0');
            sum[i] = s[i] - '0';
            if(i) {
                cnt[i] += cnt[i - 1];
                pref[i] = pref[i - 1];
                pref[i] %= mod;
                sum[i] += sum[i - 1];
            }

            if(s[i] != '0'){
                pref[i] = (10 * pref[i] + s[i] - '0') % mod;
            }

        }

        vector<ll> pw10(n + 1, 1);

        F(i, 1, n) pw10[i] = (10 * pw10[i - 1]) % mod;

        vector<int> ans;
        for(auto &q : queries){
            int l = q[0], r = q[1];

            int non_zero_chars = cnt[r] - (l ? cnt[l - 1] : 0); // non zero char [l, r]
            int digit_sum = sum[r] - (l ? sum[l - 1] : 0);


            ll left = (l ? pref[l - 1] : 0);
            ll tot = pref[r];
            ll curr = (tot - pw10[non_zero_chars] * left) % mod;
            curr = (curr + mod) % mod;

            ll res = (digit_sum * curr) % mod;
            ans.push_back(res);

            // debug
            // cout << l << ' ' << r << endl;
            // cout << "Total : " << tot << endl;
            // cout << "Left : " << left << endl;
            // cout << "non_zero_chars : " << non_zero_chars << endl;
            // cout << "digit_sum : " << digit_sum << endl; 
            // cout << "res : " << res << "\n\n";

            
        }

        return ans;
    }
};