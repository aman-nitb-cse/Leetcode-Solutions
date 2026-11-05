// Last updated: 11/6/2026, 5:13:34 AM
class KthLargest {
public:
    multiset<int> st;
    int k;
    KthLargest(int _k, vector<int>& nums) {
        k = _k;
        st.insert(nums.begin(), nums.end());
    }
    
    int add(int val) {
        st.insert(val);
        return *prev(st.end(), k);
    }
};