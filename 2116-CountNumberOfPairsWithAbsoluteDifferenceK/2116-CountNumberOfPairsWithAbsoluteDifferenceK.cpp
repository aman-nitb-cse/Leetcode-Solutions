// Last updated: 6/25/2026, 11:13:44 PM
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int count = 0;
        for(auto i = nums.begin(); i != nums.end(); i++){
            for(auto j = i + 1; j != nums.end(); j++){
                int diff = abs(*i - *j);
                if(diff == k) count++;
            }
        }
        return count;
    }
};