// Last updated: 6/24/2026, 3:31:33 AM
class Solution {
public:
    using ull = unsigned long long;

    const ull base = 1e6 + 3;

    vector<int> beautifulIndices(string s, string a, string b, int k) {

        ull ah = 0, bh = 0;

        for(char &c : a) ah = ah * base + c;
        for(char &c : b) bh = bh * base + c;

        int n = s.size(), an = a.size(), bn = b.size();

        vector<int> _b;

        // hash for b
        ull h = 0, pw = 1;

        for(int i = 0; i < bn; i++){
            h = h * base + s[i];
            pw *= base;
        }

        if(h == bh) _b.push_back(0);

        for(int i = bn; i < n; i++){

            h = h * base + s[i];
            h -= pw * s[i - bn];

            if(h == bh) _b.push_back(i - bn + 1);
        }

        // hash for a
        h = 0;
        pw = 1;

        for(int i = 0; i < an; i++){
            h = h * base + s[i];
            pw *= base;
        }

        vector<int> ans;

        auto store = [&](int i){
            auto it = ranges::lower_bound(_b, i - k);
            if(it != _b.end() && *it <= i + k) ans.push_back(i);
        };

        if(h == ah) store(0);

        for(int i = an; i < n; i++){

            h = h * base + s[i];
            h -= pw * s[i - an];

            if(h == ah) store(i - an + 1);
        }

        return ans;
    }
};