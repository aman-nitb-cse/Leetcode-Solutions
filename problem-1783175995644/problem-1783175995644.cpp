// Last updated: 7/4/2026, 8:09:55 PM
1class Solution {
2public:
3    int maxValidPairSum(vector<int>& nums, int k) {
4        int n = nums.size();
5
6        vector<int> suf = nums;
7
8        for(int i = n - 2; i >= 0; i--){
9            suf[i] = max(suf[i], suf[i + 1]);
10        }
11
12        int pref = INT_MIN, ans = INT_MIN;
13
14        for(int i = 0; i + k < n; i++){
15            pref = max(pref, nums[i]);
16
17            ans = max(ans, pref + suf[i + k]);
18        }
19
20        return ans;
21    }
22};