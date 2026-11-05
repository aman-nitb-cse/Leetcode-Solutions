// Last updated: 11/6/2026, 5:09:33 AM
class Solution {
public:
    int atmost(vector<int>& nums, int k){

        int n = nums.size();

        vector<int> freq(n + 1);

        int l = 0, r = 0;

        int distinct = 0;

        int count = 0;

        while(r < n){

            if(freq[nums[r]]++ == 0) distinct++;

            while(distinct > k){
                if(--freq[nums[l++]] == 0) distinct--;
            }

            count += r - l + 1;

            r++;
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return atmost(nums, k) - atmost(nums, k - 1);
    }
};