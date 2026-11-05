// Last updated: 11/6/2026, 4:38:22 AM
class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        priority_queue<int> q;
        long long ans = 0;
        for(int i = 0; i < s.size(); i++){
            q.push(nums[i]);
            if(s[i] == '1'){
                ans += q.top();
                q.pop();
            }
        }
        return ans;
    }
};