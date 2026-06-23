// Last updated: 6/24/2026, 3:26:30 AM
class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int sum = 0;

        for(int i = 0; i <= 1000; i++){
            if(abs(n - i) <= k &&  (n & i) == 0) sum += i;
        }
        return sum;
    }
};