// Last updated: 11/6/2026, 4:45:55 AM
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