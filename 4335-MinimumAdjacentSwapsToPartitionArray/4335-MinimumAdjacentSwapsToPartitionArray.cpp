// Last updated: 8/20/2026, 8:27:30 PM
class Solution {
public:
    using ll = long long;
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        ll ans = 0;
        int mod = 1e9 + 7;
        int j = 0;
        vector<int> v1;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < a) {
                ans += i - j++;
                ans %= mod;
            }
            else v1.push_back(nums[i]);
        }

        j = 0;
        for(int i = 0; i < v1.size(); i++){
            if(v1[i] >= a && v1[i] <= b) {
                ans += i - j++;
                ans %= mod;
            }
        }

        return ans;
    }
};