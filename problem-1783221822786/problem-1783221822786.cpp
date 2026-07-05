// Last updated: 7/5/2026, 8:53:42 AM
1class Solution {
2public:
3    using ll = long long;
4    int divisibleGame(vector<int>& nums) {
5        int n = nums.size();
6        int mod = 1e9 + 7;
7
8        unordered_set<int> c;
9
10        c.insert(2);
11
12        for(int &num : nums){
13            for(int d = 1; 1LL * d  * d <= num; d++){
14                if(num % d== 0){
15                    if(d > 1) c.insert(d);
16                    if(num / d > 1) c.insert(num / d);
17                }
18            }
19        }
20
21        ll ans = LLONG_MIN;
22        int bestK = 2;
23
24        int maxVal = ranges::max(nums);
25
26        for(int k : c){
27            ll sum = (nums[0] % k) ? -1LL * nums[0] : nums[0];
28            ll maxi = sum;
29
30            for(int j = 1; j < n; j++){
31                ll val = (nums[j] % k) ? -1LL * nums[j] : nums[j];
32                ll nsum = sum + val;
33
34
35                sum = max(val, nsum);
36                maxi = max(maxi, sum);
37            }
38
39            if(maxi > ans || (maxi == ans && k < bestK)){
40                ans = maxi;
41                bestK = k;
42            }
43        }
44
45        ans = ans * bestK % mod;
46        ans = (ans + mod) % mod;
47
48        return ans;
49    }
50};