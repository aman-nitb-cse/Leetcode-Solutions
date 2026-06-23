// Last updated: 6/24/2026, 3:28:34 AM
class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<string,int> mp;
        int ans = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            string num = to_string(nums[i]);
            string s = num;

            // remove trailing 0
            while(!s.empty() && s.back() == '0') s.pop_back();

            ranges::reverse(s);
            
            // search num in map
            if(mp.count(num)) ans = min(ans, i - mp[num]);

            // store reverse in map
            mp[s] = i;
        }
        return ans < INT_MAX ? ans : -1;
    }
};