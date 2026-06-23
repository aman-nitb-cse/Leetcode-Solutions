// Last updated: 6/24/2026, 3:27:38 AM
class Solution {
public:
    vector<long long> fac;
    vector<long long> inv;
    int m = 1e9 + 7;
    long long c(int n, int r){
        if(r < 0 || r > n) return 0;
        long long a =  fac[n] * inv[r] % m;
        a = a * inv[n - r] % m;
        return a;
    }
    long long power(long long a, long long b){
        long long answer = 1;
        while(b){
            if(b&1) answer = answer * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return answer;
    }
    int countVisiblePeople(int n, int pos, int k) {

        fac.assign(n, 1);
        inv.assign(n, 1);
        for(int i = 2; i < n; i++){
            fac[i] = i * fac[i - 1] % m;
        }
        inv[n - 1] = power(fac[n - 1], m - 2);
        for(int i = n - 2; i >= 0; i--){
            inv[i] = inv[i + 1] * (i + 1) % m;
        }

        
        long long ans = 0;
        int left = pos;
        int right = n - pos - 1;

        for(int i = 0; i <= max(left, right); i++){
            ans += 2 * c(left, i) * c(right, k - i) % m;
            ans %= m;
        }
        return ans;
    }
};