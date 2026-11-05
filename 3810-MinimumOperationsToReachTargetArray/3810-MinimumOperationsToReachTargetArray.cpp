// Last updated: 11/6/2026, 4:37:13 AM
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        unordered_set<int> st;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != target[i] && st.find(nums[i]) == st.end()) {
                count++;
                st.insert(nums[i]);
            }
        }
        return count;
    }
};