// Last updated: 6/24/2026, 3:28:16 AM
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