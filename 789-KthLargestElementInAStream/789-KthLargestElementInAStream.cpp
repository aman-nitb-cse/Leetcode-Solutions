// Last updated: 6/25/2026, 11:21:21 PM
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