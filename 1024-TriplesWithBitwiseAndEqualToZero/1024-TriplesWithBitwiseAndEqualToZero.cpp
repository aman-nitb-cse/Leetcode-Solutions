// Last updated: 6/25/2026, 11:19:15 PM
class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int ands[1 << 16] = {0};
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums.size(); j++){
                ands[nums[i] & nums[j]]++;
            }
        }

        int count = 0;
        for(int &i : nums){
            for(int j = 0; j < (1 << 16); j++){
                if((i & j) == 0) count += ands[j];
            }
        }
        return count;
    }
};