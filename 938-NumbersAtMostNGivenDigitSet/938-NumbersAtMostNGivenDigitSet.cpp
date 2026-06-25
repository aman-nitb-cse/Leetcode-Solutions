// Last updated: 6/25/2026, 11:20:01 PM
class Solution {
public:
    int dp[12][2];
    bitset<9> digit;

    int digitDP(string &s, int i = 0, int tight = 1){
        if(i == s.size()) return 1;

        auto &_dp = dp[i][tight];
        if(_dp != -1) return _dp;

        _dp = 0;
        char limit = tight ? s[i] : '9';

        for(char d = '1'; d <= limit; d++){
            if(digit[d - '1']) _dp += digitDP(s, i + 1, tight && (d == limit));
        }
        return _dp;
    }

    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        memset(dp, -1, sizeof(dp));
        digit.reset();

        for(auto &c : digits){
            digit.set(c[0] - '1');
        }

        string s = to_string(n);
        int k = digits.size();

        int ans = 0;

        // count numbers with smaller length
        for(int l = 1; l < s.size(); l++){
            ans += pow(k, l);
        }

        // count numbers with same length
        ans += digitDP(s);

        return ans;
    }
};