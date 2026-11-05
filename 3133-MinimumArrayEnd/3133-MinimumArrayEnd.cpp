// Last updated: 11/6/2026, 4:46:32 AM
class Solution {
public:
    long long add(int n, int x){
        if(n == 0 || x == 0) return n + x;
        if(1 & x) return (add(n, x >> 1) << 1) + 1;
        return (1 & n) + (add(n >> 1, x >> 1) << 1);
    }
    long long minEnd(int n, int x) {
        return add(n - 1, x);
    }
};