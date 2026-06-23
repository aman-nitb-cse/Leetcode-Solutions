// Last updated: 6/24/2026, 3:27:39 AM
class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        
        for(long long i = 1000, c = 1; n >= i; i *= 1000, c++){
            ans += c * (min(n, (1000 * i) - 1) - i + 1);
        }
        return ans;
    }
};