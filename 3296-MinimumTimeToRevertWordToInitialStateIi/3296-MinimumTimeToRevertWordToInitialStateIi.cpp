// Last updated: 6/24/2026, 3:31:20 AM
class Solution {
public:

    using ull = unsigned long long;

    const ull BASE = 1e6 + 3;

    int minimumTimeToInitialState(string s, int k) {

        int n = s.size();

        vector<ull> pref(n), suf(n);

        // prefix hashes
        pref[0] = s[0];
        for(int i = 1; i < n; i++){

            pref[i] = pref[i - 1] * BASE + s[i];
        }

        // suffix hashes
        ull pw = 1;
        suf[n - 1] = s[n - 1];
        for(int i = n - 2; i >= 0; i--){
            pw *= BASE;
            suf[i] = s[i] * pw + suf[i + 1];
        }

        for(int i = k; i < n; i += k){
            // cout << "\npref : " << pref[n - i - 1] << "\nsuff : " << suf[i] << endl;
            if(pref[n - i - 1] == suf[i]) return i / k;
        }

        return (n + k - 1) / k;
    }
};