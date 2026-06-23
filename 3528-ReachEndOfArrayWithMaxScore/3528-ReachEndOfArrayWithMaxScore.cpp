// Last updated: 6/24/2026, 3:30:34 AM
class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long score = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[j] > nums[i] || j == nums.size() - 1){
                    score += 1LL * (j - i) * nums[i];
                    i = j - 1;
                    break;
                }
            }
        }
        return score;
    }
};