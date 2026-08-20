// Last updated: 8/20/2026, 9:04:16 PM
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> next;
        stack<int> st;
        st.push(1e9);
        for(int &i : nums2 | views::reverse){
            while(st.top() <= i) st.pop();

            next[i] = st.top() < 1e9 ? st.top() : -1;
            st.push(i);
        }

        for(int &i : nums1){
            i = next[i];
        }

        return nums1;
    }
};