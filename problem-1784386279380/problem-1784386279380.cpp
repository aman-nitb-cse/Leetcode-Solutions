// Last updated: 7/18/2026, 8:21:19 PM
1class Solution {
2public:
3    using ll = long long;
4    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
5        ll ans = 0;
6        int mod = 1e9 + 7;
7        int j = 0;
8        vector<int> v1;
9
10        for(int i = 0; i < nums.size(); i++){
11            if(nums[i] < a) {
12                ans += i - j++;
13                ans %= mod;
14            }
15            else v1.push_back(nums[i]);
16        }
17
18        j = 0;
19        for(int i = 0; i < v1.size(); i++){
20            if(v1[i] >= a && v1[i] <= b) {
21                ans += i - j++;
22                ans %= mod;
23            }
24        }
25
26        return ans;
27    }
28};