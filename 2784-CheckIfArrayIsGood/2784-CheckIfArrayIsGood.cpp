// Last updated: 11/6/2026, 4:50:08 AM
class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;
        bitset<201> seen;
        bool dup = 0;

        for (auto& num : nums) {
            if (num > n) return false;

            if (seen.test(num)) {
                if (num < n || dup) return false;
                dup |= 1;
                continue;
            }

            seen.set(num);
        }

        return true;
    }
};