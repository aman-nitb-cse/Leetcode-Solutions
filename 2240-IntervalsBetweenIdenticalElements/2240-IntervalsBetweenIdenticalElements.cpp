// Last updated: 6/25/2026, 11:12:57 PM
class Solution {
public:
    vector<long long> getDistances(vector<int>& nums) {
        unordered_map<int,vector<long long>> dp; 
        // 0 : big_sum, 
        // 1 : big_count
        // 2 : small_sum
        // 3 : small_count

        for(int i = 0; i < nums.size(); i++){
            auto &v = dp[nums[i]];
            if(v.empty()) v.resize(4);

            v[0] += i;
            v[1]++;
        }

        vector<long long> arr(nums.size());

        for(int i = 0; i < arr.size(); i++){
            auto &v = dp[nums[i]];
            v[0] -= i;
            v[1]--;

            arr[i] = 0LL + v[0] - v[2] - i * (v[1] - v[3]);

            v[2] += i;
            v[3]++;
        }
        return arr;
    }
};