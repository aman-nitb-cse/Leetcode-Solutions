// Last updated: 6/24/2026, 3:29:03 AM
class Solution {
public:
    using ll = long long;

    long long countDistinct(long long n) {

        vector<ll> p(20, 1);

        for(int i = 1; i < 20; i++){
            p[i] = p[i - 1] * 9;
        }

        string s = to_string(n);

        int l = s.size();

        // count valid numbers with fewer digits
        ll cnt = (p[l] - 9) / 8;

        // count valid numbers with same length
        for(int i = 0; i < l; i++){

            int cur = s[i] - '0';

            if(cur == 0) return cnt;

            cnt += (cur - 1) * p[l - i - 1];

        }

        // n itself contains no zero digit
        cnt++;

        return cnt;
    }
};