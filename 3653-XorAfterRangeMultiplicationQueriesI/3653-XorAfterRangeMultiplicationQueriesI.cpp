// Last updated: 11/6/2026, 4:40:45 AM
class Solution {
public:
    int m = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto &q : queries){
            for(int i = q[0]; i <= q[1]; i += q[2]) 
                nums[i] = (1LL * nums[i] * q[3]) % m;
        }

        int x = 0;
        for(int &i : nums){
            x ^= i;
        }
        return x;
    }
};