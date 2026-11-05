// Last updated: 11/6/2026, 4:47:12 AM
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