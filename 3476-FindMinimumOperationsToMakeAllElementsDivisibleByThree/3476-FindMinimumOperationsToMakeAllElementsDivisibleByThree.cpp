// Last updated: 6/24/2026, 3:30:41 AM
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;

        for(int &i : nums){
            count += (i % 3 != 0);
        }
        return count;
    }
};