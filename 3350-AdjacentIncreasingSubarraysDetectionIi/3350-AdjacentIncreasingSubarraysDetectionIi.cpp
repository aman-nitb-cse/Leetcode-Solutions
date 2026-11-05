// Last updated: 11/6/2026, 4:44:25 AM
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        vector<int> v = {0};
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] <= nums[i - 1]) v.push_back(i);
        }
        v.push_back(nums.size());

        for(int i = 0; i < v.size() - 1; i++){
            v[i] = v[i + 1] - v[i];
        }
        v.pop_back();

        int k = 1;
        for(int i = 0; i < v.size() - 1; i++){
            k = max(k, min(v[i], v[i + 1]));
            k = max(k, v[i] / 2);
        }
        return max(k, v.back() / 2);
    }
};