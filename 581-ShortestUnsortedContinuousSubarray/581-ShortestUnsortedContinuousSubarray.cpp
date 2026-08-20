// Last updated: 8/20/2026, 9:02:47 PM
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        multiset<int> st(nums.begin(), nums.end());

        int s = 0, e = nums.size() - 1;

        while(s <= e){
            if(*st.begin() == nums[s]) st.erase(st.find(nums[s++]));
            else if(*st.rbegin() == nums[e]) st.erase(st.find(nums[e--]));
            else break;
        }

        return e - s + 1;
    }
};