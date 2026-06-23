// Last updated: 6/24/2026, 3:28:42 AM
class Solution {
public:
    long long dp[16][2][10];
    bitset<16> idx;
    long long digitDP(string &s, int i, int tight, char prev = '0'){
        if(i == s.size()) return 1;
        auto &_dp = dp[i][tight][prev - '0'];
        if(_dp != -1) return _dp;
    
        char start = idx[i] ? prev : '0';
        char limit = tight ? s[i] : '9';
        _dp = 0;
    
        for(int d = start; d <= limit; d++){
            _dp += digitDP(
                s,                      
                i + 1, 
                tight && (d == limit),
                idx[i] ? d : prev
            );
        }
        return _dp;
    }
    string str(long long n){
        string s = to_string(n);
        return string(16 - s.size(), '0') + s;
    }
    long long countGoodIntegersOnPath(long long l, long long r, string dir) {
        int i = 0, j = 0;
        idx.set(0);
        for(char &c : dir){
            if(c == 'D') i++;
            else j++;
            idx.set(i * 4 + j);
        }
        memset(dp, -1, sizeof(dp));
        string right = str(r);
        long long ans = digitDP(right, 0, 1);

        memset(dp, -1, sizeof(dp));
        string left = str(l - 1);
        ans -= digitDP(left, 0, 1);
        
        return ans;
    }
};