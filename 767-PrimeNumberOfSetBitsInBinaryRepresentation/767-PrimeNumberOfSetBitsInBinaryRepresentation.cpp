// Last updated: 6/25/2026, 11:21:34 PM
class Solution {
public:
    int isPrime(int n){
        if(n == 1) return false;
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0) return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        vector<int> v(right + 1);
        for(int i = 1; i <= right; i++){
            v[i] = v[i >> 1] + (i & 1);
        }
        int count = 0;
        while(left <= right){
            count += isPrime(v[left++]);
        }
        return count;
    }
};