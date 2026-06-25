// Last updated: 6/25/2026, 11:16:00 PM
class Solution {
public:
    int m = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sums;

        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum = (sum + nums[j]) % m;
                sums.push_back(sum);
            }
        }
        ranges::sort(sums);
        return accumulate(sums.begin() + left - 1, sums.begin() + right, 0,
            [&](int x, int y){
                return (x + y) % m;
            }
        );
    }
};