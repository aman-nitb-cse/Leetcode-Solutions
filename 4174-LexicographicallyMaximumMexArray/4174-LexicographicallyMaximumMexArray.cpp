// Last updated: 6/24/2026, 3:28:24 AM
class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        int n = nums.size();

        vector<int> cnt(n + 2);

        for(int &x : nums){
            if(x <= n) cnt[x]++;
        }

        set<int> miss;

        for(int i = 0; i <= n + 1; i++){
            if(cnt[i] == 0) miss.insert(i);
        }

        vector<int> ans;
        int i = 0;
        while(i < n){
            int mex = *miss.begin();
            ans.push_back(mex);

            if(mex == 0){

                if(nums[i] <= n){
                    cnt[nums[i]]--;

                    if(cnt[nums[i]] == 0) miss.insert(nums[i]);
                }

                i++;
                continue;
            }

            unordered_set<int> st;

            while(st.size() < mex){
                int x = nums[i];

                if(x <= n){
                    cnt[x]--;
                    if(cnt[x] == 0) miss.insert(x);
                }

                if(x < mex) st.insert(x);

                i++;
            }

        }
        return ans;
    }
};