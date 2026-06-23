// Last updated: 6/24/2026, 3:26:48 AM
class Solution {
public:
    int rev(int n){
        int r = 0;
        while(n){
            r = r * 10 + n % 10;
            n /= 10;
        }
        return r;
    }

    bool isPrime(int n){
        if(n < 2) return false;
        if(n % 2 == 0) return n == 2;
        for(int i = 3; i * i <= n; i += 2){
            if(n % i == 0) return false;
        }
        return true;
    }

    int sumOfPrimesInRange(int n) {
        int r = rev(n);
        int l = min(n, r), h = max(n, r);

        int sum = 0;
        for(int i = l; i <= h; i++){
            if(isPrime(i)) sum += i;
        }
        return sum;
    }
};