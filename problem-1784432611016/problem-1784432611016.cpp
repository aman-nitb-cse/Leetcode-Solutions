// Last updated: 7/19/2026, 9:13:31 AM
1class Solution {
2public:
3    vector<bool> transformStr(string s, vector<string>& strs) {
4        vector<bool> ans;
5        int n = s.size();
6        for(auto& x : strs){
7            int e1 = 0, e0 = 0, cnt = 0;
8
9            for(int i = 0; i < n; i++){
10                if(s[i] == '1') e1++;
11                else e0++;
12
13
14                if(x[i] == '1') e1--;
15                else if(x[i] == '0') e0--;
16                else cnt++;
17            }
18
19            if(e0 < 0 || e1 < 0){
20                ans.push_back(false);
21                continue;
22            }
23
24            for(int i = 0; i < n; i++){
25                if(x[i] == '?' && e0 > 0){
26                    x[i] = '0';
27                    e0--;
28                }
29                else if(x[i] == '?'){
30                    x[i] = '1';
31                }
32            }
33
34            vector<int> a, b;
35
36            for(int i = 0; i < n; i++){
37                if(s[i] == '1') a.push_back(i);
38                if(x[i] == '1') b.push_back(i);
39            }
40
41            bool valid = true;
42
43            for(int i = a.size() - 1; i >= 0; i--){
44                if(a[i] > b[i]){
45                    valid = false;
46                    break;
47                }
48            }
49
50            ans.push_back(valid);
51        }
52
53        return ans;
54    }
55};