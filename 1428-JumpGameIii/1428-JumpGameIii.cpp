// Last updated: 6/25/2026, 11:17:10 PM
class Solution {
public:
    unordered_set<int> st;
    bool canReach(vector<int>& arr, int i) {
        if(st.count(i) || i < 0 || i >= arr.size()) return false;
        st.insert(i);
        return arr[i] == 0 || canReach(arr, i + arr[i]) || canReach(arr, i - arr[i]);
    }
};