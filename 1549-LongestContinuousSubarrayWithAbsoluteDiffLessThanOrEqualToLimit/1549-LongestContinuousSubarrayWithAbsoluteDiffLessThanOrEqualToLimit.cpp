// Last updated: 6/25/2026, 11:16:09 PM
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int s = 0, e = 0, n = nums.size(), size = 1;
        multiset<int> st = {nums[0]};
        while(e < n){
            if(*st.rbegin() - *st.begin() <= limit){ // expand
                size = max(size, e - s + 1);
                e++;
                if(e < n) st.insert(nums[e]);
            }
            else { // shrink
                st.erase(st.find(nums[s++]));
            }
        }
        return size;
    }
};