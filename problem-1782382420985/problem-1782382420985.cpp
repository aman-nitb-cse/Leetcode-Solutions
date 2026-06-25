// Last updated: 6/25/2026, 3:43:40 PM
1class Solution {
2public:
3    int maxFixedPoints(vector<int>& A) {
4        
5        vector<pair<int,int>> b;
6
7        for(int i = 0; i < A.size(); i++){
8
9            if(i >= A[i]) b.push_back({i - A[i], A[i]});
10        }
11
12        sort(b.begin(), b.end());
13
14        vector<int> lis;
15
16        for(auto &[x,y] : b){
17
18            auto it = ranges::lower_bound(lis, y);
19
20            if(it == lis.end()) lis.push_back(y);
21
22            else *it = y;
23        }
24
25        return lis.size();
26    }
27};