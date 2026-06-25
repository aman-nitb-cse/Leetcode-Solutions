// Last updated: 6/25/2026, 11:11:03 PM
class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if(k == 0) return (nums1 == nums2) - 1;
        long long diff = 0;
        long long sum = 0;
        for(int i = 0; i < nums1.size(); i++){
            nums1[i] -= nums2[i];
            if(nums1[i] % k) return -1;
            nums1[i] /= k;
            sum += nums1[i];
            diff += abs(nums1[i]);
        }

        if(sum) return -1;
        return diff / 2;
    }
};