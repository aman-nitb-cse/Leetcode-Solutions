// Last updated: 6/25/2026, 11:12:38 PM
class Solution {
public:
    long long sumUpto(long long n){
        return n * (n + 1) / 2;
    }
    long long minimalKSum(vector<int>& nums, int k) {
        nums.push_back(0);
        nums.push_back(INT_MAX);
        sort(nums.begin(), nums.end());
        long long count = 0, sum = 0;
        for(int i = 1; count < k and i < nums.size(); i++){
            if(nums[i] - nums[i - 1] < 2) continue;
            long long present = nums[i] - nums[i - 1] - 1, need = k - count;
            long long take = min(present, need);
            count += take;
            sum += sumUpto(nums[i - 1] + take) - sumUpto(nums[i - 1]);
        }
        return sum;
    }
};