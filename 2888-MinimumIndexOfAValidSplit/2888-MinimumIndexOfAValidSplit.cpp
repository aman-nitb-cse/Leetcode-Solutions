// Last updated: 6/24/2026, 3:32:09 AM
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size(), d = 0, f = 0;
        for(int &i : nums){
            if(f == 0){
                d = i;
                f = 1;
            }
            else if(i == d) f++;
            else f--;
        }
        f = ranges::count(nums, d);
        int left_count = 0, right_count = f;

        for(int i = 0; i < n; i++){
            if(nums[i] == d){
                left_count++;
                right_count--;
            }
            int left_size = i + 1;
            int right_size = n - left_size;

            if(left_count > left_size / 2 && right_count > right_size / 2) return i;
        }
        return -1;
    }
};