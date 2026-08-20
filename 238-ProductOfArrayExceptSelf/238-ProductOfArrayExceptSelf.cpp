// Last updated: 8/20/2026, 9:10:22 PM
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int zeros = 0;
        for(int &i : nums){
            if(i) product *= i;
            else zeros++;
        }

        if(zeros > 1){
            for(int &i : nums) i = 0;
            return nums;
        }

        for(int &i : nums){
            if(zeros){ // 0 present
                if(i) i = 0;
                else i = product;
            }
            else { // 0 absent
                i = product / i;
            }
        }
        return nums;
    }
};