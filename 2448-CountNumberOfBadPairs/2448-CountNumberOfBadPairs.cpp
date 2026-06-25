// Last updated: 6/25/2026, 11:11:58 PM
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long sum=((n)*(n-1))/2;
        unordered_map<long long,long long>mpp;
        for(int i=0;i<n;i++){
            sum-=mpp[nums[i]-i]++;
        }       
        return sum;
    }
};