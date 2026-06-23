// Last updated: 6/24/2026, 3:27:53 AM
class Solution {
public:
    bool isDigitorialPermutation(int n) {

        // calcluate factorial
        int fac[10] = {0};
        fac[0] = 1;
        for(int i = 1; i < 10; i++){
            fac[i] = fac[i - 1] * i;
        }

        // hashing
        int hash[10] = {0};

        // calculate factorial sum
        long long sum = 0;
        while(n) {
            sum += fac[n % 10];
            hash[n % 10]++;
            n /= 10;
        }
        
        while(sum) {
            hash[sum % 10]--;
            sum /= 10;
        }

        return all_of(begin(hash), end(hash), [](int x){ return x == 0;});
    }
};