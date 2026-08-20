// Last updated: 8/20/2026, 9:04:37 PM
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        vector<double> v(nums.begin(), nums.begin() + k);
        ranges::sort(v);
        auto calc = [&](){
            if(k&1) ans.push_back(v[k / 2]);
            else ans.push_back((v[k / 2] + v[k / 2 - 1]) / 2.0);
        };
        for(int i = 0; i <= nums.size() - k; i++){
            // store ans
            calc();
            // erase
            v.erase(ranges::lower_bound(v, nums[i]));
            // insert
            if(i + k < nums.size()) v.insert(ranges::lower_bound(v, nums[i + k]), nums[i + k]);
        }
        return ans;
    }
};