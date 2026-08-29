// Last updated: 8/29/2026, 8:24:47 PM
1class Solution {
2public:
3    vector<string> largestString(vector<int>& nums) {
4        vector<string> ans;
5
6        int p = (1 << 25);
7
8        for(int &i : nums){
9            int z = i / p;
10            int rem = i % p;
11
12            string s;
13
14            for(int j = 0; j < z; j++) s += 'z';
15
16
17            // cout << s << endl;
18
19            for(int j = 24; j >= 0; j--){
20                if((rem >> j) & 1){
21                    s += (char) ('a' + j);
22                }
23                // cout << s << endl;
24            }
25
26            ans.push_back(s);
27        }
28        return ans;
29    }
30};