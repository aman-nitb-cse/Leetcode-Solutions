// Last updated: 7/5/2026, 8:03:42 AM
1class Solution {
2public:
3    int maxDigitRange(vector<int>& nums) {
4        int maxi = 0, sum = 0;
5
6        for(int i : nums){
7
8            int x = i;
9            int mx = 0, mn = 9;
10
11            while(i){
12                mx = max(mx, i % 10);
13                mn = min(mn, i % 10);
14
15                i /= 10;
16            }
17
18            if(maxi == mx - mn) sum += x;
19            else if(mx - mn > maxi){
20                maxi = mx - mn;
21                sum = x;
22            }
23        }
24        return sum;
25    }
26};