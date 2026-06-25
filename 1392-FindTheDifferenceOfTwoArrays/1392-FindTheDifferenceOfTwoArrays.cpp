// Last updated: 6/25/2026, 11:17:29 PM
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> m1, m2;   

        for(int &i : nums1) m1[i] = false; 
        for(int &i : nums2) m2[i] = false;

        vector<vector<int>> ans(2);

        for(int &i : nums1){
            if(!m2.count(i) && !m1[i]){
                ans[0].push_back(i);
                m1[i] = true;
            }
        }

        for(int &i : nums2){
            if(!m1.count(i) && !m2[i]){
                ans[1].push_back(i);
                m2[i] = true;
            }
        }
        return ans;
    }
};