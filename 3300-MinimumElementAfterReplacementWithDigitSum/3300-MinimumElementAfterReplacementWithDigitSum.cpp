// Last updated: 11/6/2026, 4:44:32 AM
class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for(int &i : nums){
            int sum = 0;
            while(i){
                sum += i % 10;
                i /= 10;
            }
            ans = min(ans, sum);
        }
        return ans;
    }
};