// Last updated: 6/24/2026, 3:28:30 AM
class Solution {
public:
    using ll = long long;
    long long minimumCost(string s, string t, int fc, int sc, int cc) {
        array<ll,2> cnt{};

        for(auto [x, y] : views::zip(s, t)){
            if(x != y) cnt[x - '0']++;
        }

        auto [mn, mx] = ranges::minmax(cnt);

        ll allflips = (mn + mx) * fc;
        ll swaps = mn * sc + min(((mx - mn) / 2) * (cc + sc) + ((mn + mx) & 1) * fc, (mx - mn) * fc);


        return min(allflips, swaps);
    }
};