// Last updated: 8/20/2026, 9:01:51 PM
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector <int> hash(nums.size() + 1);
        for(int &i : nums) hash[i]++;

        vector <int> ans(2);
        for(int i = 1; i < hash.size(); i++){
            if(hash[i] == 0) ans[1] = i;
            if(hash[i] == 2) ans[0] = i;
            if(ans[1] and ans[0]) return ans;
        }
        return {};
    }
};