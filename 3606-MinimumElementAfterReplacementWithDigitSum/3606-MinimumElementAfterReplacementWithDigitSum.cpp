// Last updated: 6/24/2026, 3:30:19 AM
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