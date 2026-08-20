// Last updated: 8/20/2026, 9:10:20 PM
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset <int> st;
        int temp;
        for(int i = 0; i < k; i++) st.insert(nums[i]);
        for(int i = 0; i <= nums.size() - k; i++){
            if(i){
                st.erase(st.find(temp));
                st.insert(nums[i + k - 1]);
            }
            temp = nums[i];
            nums[i] = *st.rbegin();
        }
        nums.resize(nums.size() - k + 1);
        return nums;
    }
};