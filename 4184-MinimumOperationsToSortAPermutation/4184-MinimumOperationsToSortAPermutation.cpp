// Last updated: 6/24/2026, 3:28:20 AM
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n =  nums.size();
        // check sorted rotation
        int zero = ranges::find(nums, 0) - nums.begin();
        int prev = nums[zero];
        bool flag = true;
        for(int j = (zero + 1) % n; j != zero; j = (j + 1) % n){
            if(nums[j] < prev){
                flag = false;
                break;
            }
            prev = nums[j];
        }

        if(flag) return min(zero, 2 + n - zero);

        // check rev-sorted
        int maxi = ranges::find(nums, n - 1) - nums.begin();
        int _prev = nums[maxi];
        bool _flag = true;
        for(int j = (maxi + 1) % n; j != maxi; j = (j + 1) % n){
            if(nums[j] > _prev){
                _flag = false;
                break;
            }
            _prev = nums[j];
        }

        if(_flag) return min(zero + 2, n - zero);
        return -1;
    }
};