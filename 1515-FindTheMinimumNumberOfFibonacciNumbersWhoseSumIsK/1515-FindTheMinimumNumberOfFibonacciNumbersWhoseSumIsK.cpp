// Last updated: 6/25/2026, 11:16:25 PM
class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fib = {1,2};
        while(fib.back() <= k)
            fib.push_back(fib.back() + fib[fib.size()-2]);

        int cnt = 0;

        for(int i = fib.size()-1; i >= 0; i--){
            if(fib[i] <= k){
                k -= fib[i];
                cnt++;
            }
            if(k == 0) break;
        }
        return cnt;
    }
};