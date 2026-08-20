// Last updated: 8/20/2026, 9:19:48 PM
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        for(int i = 0; i < nums.size(); i++){
            int s = i + 1, e = nums.size() - 1;
            while(s < e){
                int sum = nums[i] + nums[s] + nums[e];
                if(sum == 0) st.insert({nums[i], nums[s++], nums[e--]});
                else if(sum > 0) e--;
                else s++;
            }
        }
        return vector<vector<int>> (st.begin(), st.end());
    }
};