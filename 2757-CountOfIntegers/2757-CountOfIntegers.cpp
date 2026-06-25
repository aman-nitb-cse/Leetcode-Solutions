// Last updated: 6/25/2026, 11:10:33 PM
class Solution {
public:
    int mini, maxi, dp[23][2][401], mod = 1e9 + 7;
    int digitDP(string &s, int i = 0, int tight = 1, int sum = 0){
        if(sum > maxi) return 0;
        if(i == s.size()) return sum >= mini;
        auto &_dp = dp[i][tight][sum];
        if(_dp != -1) return _dp;

        char limit = tight ? s[i] : '9';
        _dp = 0;

        for(int d = '0'; d <= limit; d++){
           _dp = (_dp + digitDP(s, i + 1, tight && (d == limit), sum + (d - '0'))) % mod;
        }
        return _dp;
    }
    int count(string a, string b, int min_sum, int max_sum) {
        mini = min_sum, maxi = max_sum;
        memset(dp, -1, sizeof(dp));
        int right = digitDP(b);
        memset(dp, -1, sizeof(dp));
        int left = digitDP(a);
        int ans = (right - left + mod) % mod;
        // check for a
        int sum = 0;
        for(char &i : a) sum += i - '0';
        if(sum >= mini && sum <= maxi) ans = (ans + 1) % mod;
        
        return ans;
    }
};