// Last updated: 6/25/2026, 11:19:26 PM
class Solution {
public:
    bool isValid(int x, int y, int z){
        if(x + y <= z) return false;
        if(x + z <= y) return false;
        if(y + z <= x) return false;
        return true;
    }
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b){ return a > b;});
        for(int i = 0; i < nums.size() - 2; i++){
            if(isValid(nums[i], nums[i + 1], nums[i + 2])){
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }
        return 0;
    }
};