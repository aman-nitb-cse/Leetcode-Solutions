// Last updated: 6/24/2026, 3:27:45 AM
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> v;
        int n = nums.size();
        int mx = nums[0];
        for(int &i : nums){
            mx = max(mx, i);
            v.push_back(gcd(i, mx));
        }

        ranges::sort(v);
        long long sum = 0;
        for(int i = 0; i < n / 2; i++){
            sum += gcd(v[i], v[n - 1 - i]);
        }
        return sum;
    }
};