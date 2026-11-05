// Last updated: 11/6/2026, 4:50:29 AM
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());

        int uq = st.size();
        int n = nums.size(), ans = 0;

        for(int i = 0; i < n; i++){
            st.clear();
            for(int j = i; j < n; j++){
                st.insert(nums[j]);

                if(st.size() == uq) ans++;
            }
        }

        return ans;
    }
};