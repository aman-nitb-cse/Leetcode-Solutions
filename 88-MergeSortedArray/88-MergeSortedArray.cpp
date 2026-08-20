// Last updated: 8/20/2026, 9:16:03 PM
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector <int> temp(nums1.begin(), nums1.begin() + m);
        nums1.clear();
        int i = 0, j = 0;
        while(nums1.size() < m + n){
            if(i >= m) nums1.push_back(nums2[j++]);
            else if(j >= n or temp[i] <= nums2[j]) nums1.push_back(temp[i++]);
            else if(temp[i] > nums2[j]) nums1.push_back(nums2[j++]);
            // if(j + i == m + n) return;
        }
    }
};