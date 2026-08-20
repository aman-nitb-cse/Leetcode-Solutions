// Last updated: 8/20/2026, 9:08:29 PM
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;

        for (int& i : nums) {
            if (i <= first) first = i;
            else if (i <= second) second = i;
            else return true;
        }
        return false;
    }
};