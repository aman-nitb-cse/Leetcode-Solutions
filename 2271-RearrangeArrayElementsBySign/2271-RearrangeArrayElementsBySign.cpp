// Last updated: 6/25/2026, 11:12:48 PM
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int p = 0; // +ve : even indices
        int n = 1; // -ve : odd indices

        vector<int> v(nums.size());

        for(int &i : nums){
            if(i < 0){
                v[n] = i;
                n += 2;
            }
            else {
                v[p] = i;
                p += 2;
            }
        }
        return v;
    }
};