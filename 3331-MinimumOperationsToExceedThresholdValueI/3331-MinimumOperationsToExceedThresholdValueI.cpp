// Last updated: 6/24/2026, 3:31:10 AM
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int count = 0;
        for(int &i : nums){
            count += (i < k);
        }
        return count;
    }
};