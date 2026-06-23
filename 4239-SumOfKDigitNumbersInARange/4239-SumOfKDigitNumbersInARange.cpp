// Last updated: 6/24/2026, 3:27:47 AM
class Solution {
public:
    int mod = 1e9 + 7;
    long long power(long long a, long long b){
        long long ans = 1;
        while(b){
            if(b & 1) ans = ans * a % mod;
            a = a * a % mod;
            b >>= 1;             
        }
        return ans;
    }
    int sumOfNumbers(int l, int r, int k) {
        int n = r - l + 1;
        int sum = (l + r) * (n) / 2;
        long long a = (power(10, k) - 1 + mod) % mod; 
        a = a * power(9, mod-2) % mod;
        int c = power(n, k - 1);
        return sum * (1LL * a * c % mod) % mod;
    }
};