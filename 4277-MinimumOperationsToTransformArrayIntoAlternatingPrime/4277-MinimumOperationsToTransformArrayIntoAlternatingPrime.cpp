// Last updated: 6/24/2026, 3:27:11 AM
class Solution {
public:
    const int n = 2e5;
    vector<bool> isPrime;
    vector<int> nextPrime, nextNonPrime;
    Solution(){
        isPrime.assign(n, true);
        isPrime[0] = isPrime[1] = false;

        for(int i = 2; i * i < n; i++){
            if(isPrime[i]){
                for(int j = i * i; j < n; j += i){
                    isPrime[j] = false;
                }
            }
        }

        nextPrime.assign(n, -1);
        nextNonPrime.assign(n, -1);

        int lastP = -1, lastNP = -1;

        for(int i = n - 1; i >= 0; i--){
            if(isPrime[i]) lastP = i;
            else lastNP = i;

            nextPrime[i] = lastP;
            nextNonPrime[i] = lastNP;
            
        }
    }
    int minOperations(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i & 1){ // non - prime
                int nn = nextNonPrime[nums[i]];
                ans += nn - nums[i];
            }
            else { // prime
                int np = nextPrime[nums[i]];
                ans += np - nums[i];
            }
        }
        return ans;
    }
};