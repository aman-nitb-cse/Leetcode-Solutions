// Last updated: 6/24/2026, 3:32:13 AM
class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int diff = 0;
        for(int i = 0; i < nums.size(); i++){
            // remove old 
            if(m.count(i)) diff -= m[i];
            nums[i] -= diff;

            // return if it become negetive
            if(nums[i] < 0) return false;

            // add this to diff
            if(nums[i] && i + k <= nums.size()) {
                m[i + k] = nums[i];
                diff += nums[i];
                nums[i] = 0;
            }
        }
        return ranges::none_of(nums, [](int &x){ return x;});
    }
};