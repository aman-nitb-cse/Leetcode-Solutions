// Last updated: 11/6/2026, 4:32:35 AM
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