// Last updated: 8/20/2026, 9:08:52 PM
class Solution {
public:

    vector<int> getMaxSubsequence(vector<int>& nums, int k) {
        vector<int> st;
        int remove = nums.size() - k;

        for(int x : nums) {

            while(remove && !st.empty() && st.back() < x) {
                st.pop_back();
                remove--;
            }

            st.push_back(x);
        }

        st.resize(k);
        return st;
    }

    bool greaterSuffix(vector<int>& a, int i, vector<int>& b, int j) {

        while(i < a.size() && j < b.size() && a[i] == b[j]) {
            i++;
            j++;
        }

        if(j == b.size()) return true;
        if(i == a.size()) return false;

        return a[i] > b[j];
    }

    vector<int> merge(vector<int>& a, vector<int>& b) {

        vector<int> ans;

        int i = 0, j = 0;

        while(i < a.size() || j < b.size()) {

            if(greaterSuffix(a, i, b, j)) ans.push_back(a[i++]);
            else ans.push_back(b[j++]);
        }

        return ans;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {

        vector<int> ans;

        int m = nums1.size();
        int n = nums2.size();

        for(int i = max(0, k - n); i <= min(k, m); i++) {

            auto a = getMaxSubsequence(nums1, i);
            auto b = getMaxSubsequence(nums2, k - i);

            auto cur = merge(a, b);

            ans = max(ans, cur);
        }

        return ans;
    }
};