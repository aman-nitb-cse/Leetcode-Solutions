// Last updated: 6/24/2026, 3:31:16 AM
class Solution {
public:
    using ull = unsigned long long;
    const ull base = 131;
    unordered_map<ull, int> mp;
    const int m = 1e9 + 7;
    long long countPrefixSuffixPairs(vector<string>& w) {
        // pref - suf
        ull count = 0;
        for(auto &s : w){
            ull pref = 0, suf = 0, pw = 1;
            for(int i = 0, j = s.size() - 1; i < s.size(); i++, j--){
                pref = (pref * base + s[i]) % m;
                suf = (suf + pw * s[j]) % m;
                pw = (pw * base) % m;

                if(pref == suf && mp.count(pref)) count += mp[pref];
            }
            mp[pref]++;
        }
        return count;
    }
};