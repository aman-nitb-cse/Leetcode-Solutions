// Last updated: 6/24/2026, 3:32:21 AM
class Solution {
public:
    int count_bits(long long n){
        if(n == 0) return 0;
        return (n & 1) + count_bits(n >> 1);
    }
    int makeTheIntegerZero(long long a, long long b, int bits = 0) {
        // return 0;
        if(a <= 0 && b >= 0) return -1;
        if(a > (1LL << 60)) return -1;
        int curr_bits = count_bits(a);
        if(curr_bits <= bits && a >= bits) return 0;
        int ans = makeTheIntegerZero(a - b, b, bits + 1);
        return ans == -1 ? -1 : ans + 1;
    }
};