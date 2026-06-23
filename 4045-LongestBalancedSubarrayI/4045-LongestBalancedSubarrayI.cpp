// Last updated: 6/24/2026, 3:29:06 AM
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size(), ans = 0;

        for(int i = 0; i < n; i++){
            unordered_set<int> st;
            int cnt = 0;
            for(int j = i; j < n; j++){
                int x = nums[j];
                if(!st.count(x)) cnt += (x & 1) - !(x & 1);

                st.insert(x);

                if(!cnt) ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};