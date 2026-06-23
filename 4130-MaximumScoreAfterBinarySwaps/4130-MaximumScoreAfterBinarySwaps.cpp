// Last updated: 6/24/2026, 3:28:39 AM
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