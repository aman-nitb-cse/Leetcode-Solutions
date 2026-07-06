// Last updated: 7/6/2026, 5:33:51 AM
class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int maxi = 0, sum = 0;

        for(int i : nums){

            int x = i;
            int mx = 0, mn = 9;

            while(i){
                mx = max(mx, i % 10);
                mn = min(mn, i % 10);

                i /= 10;
            }

            if(maxi == mx - mn) sum += x;
            else if(mx - mn > maxi){
                maxi = mx - mn;
                sum = x;
            }
        }
        return sum;
    }
};