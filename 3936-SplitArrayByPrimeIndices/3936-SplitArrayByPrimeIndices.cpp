// Last updated: 6/24/2026, 3:29:33 AM
class Solution {
public:
    bool isPrime(int n){
        if(n < 2) return false;
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0) return false;
        }
        return true;
    }
    long long splitArray(vector<int>& nums) {
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(isPrime(i)) sum -= nums[i];
            else sum += nums[i];
        } 
        return abs(sum);
    }
};