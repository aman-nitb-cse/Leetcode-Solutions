// Last updated: 6/25/2026, 11:21:06 PM
class Solution {
public:
    long long f(long long x){
        long long zeros = 0;
        while(x){
            x /= 5;
            zeros += x;
        }
        return zeros;
    }

    int preimageSizeFZF(int k) {
        long long s = 0, e = 5LL * (k + 1);

        while(s < e){
            long long m = (s + e) / 2;
            if(f(m) < k) s = m + 1;
            else e = m;
        }

        return (f(s) == k) ? 5 : 0;
    }
};