// Last updated: 6/25/2026, 11:14:14 PM
class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, {1, 0, 1, 0}); // flip, keep, flip, keep
        auto [a, b, c, d] = std::array{1, 0, 1, 0};
        for(int i = 1; i < n; i++){
            auto [_a, _b, _c, _d] = std::array{1, 0, 1, 0};
            if(s[i] == s[i - 1]) {
                _a += b;
                _b += a;
                _c += d;
                _d += c;
                // check can i keep both same
                
                _c = min(_c, 1 + a); // flip both
                _d = min(_d, b); // keep both
            }
            else {
                _a += a;
                _b += b;
                _c += c;
                _d += d;
            }

            a = _a;
            b = _b;
            c = _c;
            d = _d;
        }
        return (n & 1) ? min(c, d) : min(a, b);
    }
};