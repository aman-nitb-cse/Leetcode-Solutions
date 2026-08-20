// Last updated: 8/20/2026, 9:01:54 PM
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxi = INT_MIN;
        double sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i < k){
                sum += nums[i];
                continue;
            }
            if(sum / k > maxi) maxi = sum / k;
            sum += nums[i] - nums[i - k];
        }
        if(sum / k > maxi) maxi = sum / k;
        return maxi;
    }
};