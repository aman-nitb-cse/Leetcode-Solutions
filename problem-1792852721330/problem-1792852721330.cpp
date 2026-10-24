// Last updated: 10/24/2026, 8:08:41 PM
1class Solution {
2public:
3    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
4        int n = nums.size();
5
6        long long ans = 0;
7        long long len = 0;
8
9        for(int &i : nums){
10            if(i >= minK && i <= maxK){
11                len++;
12            }
13            else {
14                ans += len * (len + 1) / 2;
15                len = 0;
16            }
17        }
18        ans += len * (len + 1) / 2;
19        return ans;
20    }
21};