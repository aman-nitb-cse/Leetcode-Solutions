// Last updated: 6/25/2026, 11:15:24 PM
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        map<int,int> prefix = {{0, 0}};
        map<int,int> suffix = {{0, 0}};

        int prev = 0;
        int counter = 1;
        for(int i = 0; i < nums.size(); i++){
            prev += nums[i];
            prefix[prev] = counter++;
        }

        prev = 0;
        counter = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            prev += nums[i];
            suffix[prev] = counter++;
        }
        int ans = 1e9;
        for(auto &[val, i] : prefix){
            auto it = suffix.find(x - val);
            if(it != suffix.end()){
                int curr = i + (it->second);
                if(curr <= nums.size()) ans = min(ans, curr);
            }
        }
        return ans < 1e9 ? ans : -1;
    }
};