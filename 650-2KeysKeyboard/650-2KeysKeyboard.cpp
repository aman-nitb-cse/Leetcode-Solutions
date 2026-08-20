// Last updated: 8/20/2026, 9:01:38 PM
class Solution {
public:
    int minSteps(int n) {
        if(n == 1) return 0;
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0) return i + minSteps(n / i);
        }
        return n;
    }
};