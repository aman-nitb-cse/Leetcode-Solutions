// Last updated: 8/20/2026, 9:00:16 PM
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int freq[10001] = {};
        for(int &i : nums) freq[i]++;

        int take = 0, skip = 0;

        for(int i = 0; i <= 10000; i++){
            // take
            int _take = i * freq[i] + skip;
            int _skip = max(take, skip);

            take = _take;
            skip = _skip;
        }

        return max(take, skip);
    }
};