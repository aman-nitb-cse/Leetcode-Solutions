// Last updated: 6/24/2026, 3:26:36 AM
class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> ans;
        int value = -1;
        int cnt = 0;
        for(int &i : nums){
            if(i == value) cnt++;
            else {
                value = i;
                cnt = 1;
            }

            if(cnt > k && i == value) continue;
            ans.push_back(i);
        }
        return ans;
    }
};