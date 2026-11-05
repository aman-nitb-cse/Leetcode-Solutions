// Last updated: 11/6/2026, 5:05:03 AM
class Solution {
public:
    unordered_set<int> st;
    bool canReach(vector<int>& arr, int i) {
        if(st.count(i) || i < 0 || i >= arr.size()) return false;
        st.insert(i);
        return arr[i] == 0 || canReach(arr, i + arr[i]) || canReach(arr, i - arr[i]);
    }
};