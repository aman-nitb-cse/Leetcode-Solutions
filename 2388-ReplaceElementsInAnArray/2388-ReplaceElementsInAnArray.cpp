// Last updated: 6/25/2026, 11:12:15 PM
class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& o) {
        unordered_map <int, int> idx;
        for(int i = 0; i < nums.size(); i++){
            idx[nums[i]] = i;
        }

        for(int i = 0; i < o.size(); i++){
            int new_value = o[i][1];
            int index = idx[o[i][0]];
            nums[index] = new_value;
            idx[new_value] = index;
        }
        return nums;
    }
};