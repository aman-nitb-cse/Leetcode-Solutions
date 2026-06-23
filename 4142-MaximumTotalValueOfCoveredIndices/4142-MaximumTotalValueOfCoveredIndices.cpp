// Last updated: 6/24/2026, 3:28:33 AM
class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        long long ans = 0;
        int n = s.size();

        int i = 0;
        while(i < n){
            ans += nums[i];
            if(s[i] == '1') {
                i++;
                continue;
            }

            int mini = nums[i], j;
            for(j = i + 1; j < n && s[j] == '1'; j++){
                mini = min(mini, nums[j]);
                ans += nums[j];
            }

            ans -= mini;

            // j is n || s[j] == '0'
            i = j;

            // cout << i << ' ';
        }

        return ans;
    }
};