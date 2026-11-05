// Last updated: 11/6/2026, 4:37:39 AM
class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> v;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= 0) v.push_back(nums[i]);
        }

        if(v.size() == 0) return nums;
        k %= v.size();
        if(k == 0) return nums;

        reverse(v.begin(), v.begin() + k);
        reverse(v.begin() + k, v.end());
        reverse(v.begin(), v.end());

        int j = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= 0) nums[i] = v[j++];
        }
        return nums;
    }
};