// Last updated: 7/26/2026, 8:20:03 AM
1class Solution {
2public:
3    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
4        map<int,int> s1, s2;
5
6        for(auto &v : series1) s1[v[0]] = v[1];
7        for(auto &v : series2) s2[v[0]] = v[1];
8
9
10        vector<vector<int>> ans;
11
12        for(auto &[t, v1] : s1){
13            auto it = s2.lower_bound(t);
14
15            int v2 = (it == s2.end()) ? 0 : it->second;
16
17            ans.push_back({t, v1 + v2});
18        }
19
20        for(auto &[t, v1] : s2){
21
22            if(s1.count(t)) continue;
23            
24            auto it = s1.upper_bound(t);
25
26            int v2 = (it == s1.end()) ? 0 : it->second;
27
28            ans.push_back({t, v1 + v2});
29        }
30
31        ranges::sort(ans);
32
33        return ans;
34    }
35};