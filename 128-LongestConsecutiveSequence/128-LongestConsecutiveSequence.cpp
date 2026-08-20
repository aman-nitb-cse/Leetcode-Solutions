// Last updated: 8/20/2026, 9:14:02 PM
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set <int> st;
        for(int &i : nums) st.insert(i);

        int maxi = 0;
        int curr, prev;
        for(int i : st){
            if(i == *st.begin() or i > curr + 1) prev = i;
            curr = i;
            maxi = max(maxi, curr - prev + 1);
        }
        return maxi;
    }
};