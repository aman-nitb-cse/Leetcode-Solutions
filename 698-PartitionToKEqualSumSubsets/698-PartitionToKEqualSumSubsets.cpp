// Last updated: 6/25/2026, 11:37:06 PM
class Solution {
public:
    int target;
    vector<bool> visited;

    bool solve(vector<int>& nums, int curr, int k, int i = 0){
        if(k == 0) return true;
        if(curr == target) return solve(nums, 0, k - 1);

        for(int j = i; j < nums.size(); j++){
            if(visited[j]) continue;
            if(curr + nums[j] > target) continue;

            visited[j] = true;
            if(solve(nums, curr + nums[j], k, j + 1)) return true;
            visited[j] = false;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k) return false;

        target = sum / k;

        ranges::sort(nums, greater<>());

        visited.assign(nums.size(), false);

        return solve(nums, 0, k);
    }
};