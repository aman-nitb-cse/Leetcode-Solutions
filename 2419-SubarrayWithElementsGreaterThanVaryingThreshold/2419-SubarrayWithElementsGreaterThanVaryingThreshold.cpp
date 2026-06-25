// Last updated: 6/25/2026, 11:12:07 PM
class Solution {
public:

    int ans = -1;

    void dnc(vector<int>& nums, int x, int l, int r){

        if(l > r || ans != -1) return;

        int y = x / (r - l + 1), prev = l;

        bool valid = true;

        for(int i = l; i <= r; i++){
            if(nums[i] <= y){
                valid = false;
                dnc(nums, x, prev, i - 1);
                prev = i + 1;
            }
        }

        if(prev != l) dnc(nums, x, prev, r);

        if(valid) ans = r - l + 1;
    }

    int validSubarraySize(vector<int>& nums, int x) {
        dnc(nums, x, 0, (int)nums.size() - 1);
        return ans;
    }
};