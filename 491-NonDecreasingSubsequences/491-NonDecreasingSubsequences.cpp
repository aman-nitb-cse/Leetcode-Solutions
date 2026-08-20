// Last updated: 8/20/2026, 9:04:28 PM
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void bt(vector<int>& nums, int i = 0) {
        if (i >= nums.size()) {
            if (curr.size() > 1) ans.push_back(curr);
            return;
        }

        int prev = curr.empty() ? -101 : curr.back();

        // take
        if (nums[i] >= prev) {
            curr.push_back(nums[i]);
            bt(nums, i + 1);
            curr.pop_back();
        }

        // skip — but only if we haven't skipped this value before at this level
        if (nums[i] != prev) {  // ← key fix: avoid duplicate subsequences
            bt(nums, i + 1);
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        bt(nums);
        return ans;
    }
};