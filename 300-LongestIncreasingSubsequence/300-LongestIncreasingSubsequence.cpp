// Last updated: 8/20/2026, 9:09:22 PM
class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {

        vector<int> lis;

        for(int x : nums){

            auto it = ranges::lower_bound(lis, x);

            if(it == lis.end()) lis.push_back(x);

            else *it = x;
        }

        return lis.size();
    }
};