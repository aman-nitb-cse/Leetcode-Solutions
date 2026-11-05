// Last updated: 11/6/2026, 4:32:50 AM
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