// Last updated: 6/24/2026, 3:27:10 AM
class Solution {
public:
    int m = 1e9 + 7;
    long long binexp(long long a, long long b){
        long long ans = 1;
        a %= m;

        while(b > 0){
            if(b & 1) ans = (ans * a) % m;

            a = (a * a) % m;
            b >>= 1;
        }
        return ans;
    }
    int maxValue(vector<int>& ones, vector<int>& zeros) {
        vector<string> v;
        for(auto [one, zero] : views::zip(ones, zeros)){
            string s = string(one, '1') + string(zero, '0');
            v.push_back(s);
        }

        ranges::sort(v,
            [](auto& a, auto& b){
                return a + b > b + a;
            }
        );

        long long ans = 0;
        long long p = 0;
        for(string &s : v | views::reverse){
            for(char &c : s | views::reverse){
                if(c == '1') {
                    ans += binexp(2, p);
                    ans %= m;
                }
                p++;
            }
        }
        return ans;
    }
};