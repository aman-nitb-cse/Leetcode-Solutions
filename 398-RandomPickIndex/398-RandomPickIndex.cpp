// Last updated: 8/20/2026, 9:06:44 PM
class Solution {
public:
    unordered_map<int, vector<int>> idx;
    Solution(vector<int>& nums) {
        srand(time(0));
        for(int i = 0; i < nums.size(); i++){
            idx[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        auto &v = idx[target];
        int n = v.size();
        return v[rand() % n];
    }
};