// Last updated: 8/29/2026, 9:08:20 PM
1class SparseTable{
2private:
3    int n;
4    vector<vector<int>> st;
5public:
6    SparseTable(vector<int>& arr){
7
8        n = arr.size();
9
10        if(n == 0) return;
11
12        int max_log = log2(n) + 1;
13
14        st.assign(n, vector<int> (max_log));
15
16        for(int i = 0; i < n; i++){
17            st[i][0] = arr[i];
18        }
19
20        for(int j = 1; j < max_log; j++){
21            for(int i = 0; i + (1 << j) <= n; i++){
22                st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
23            }
24        }
25    }
26    int query(int ql, int qr){
27        if(ql < 0 || qr >= n || ql > qr) return 0;
28        int j = log2(qr - ql + 1);
29
30        return gcd(st[ql][j], st[qr - (1 << j) + 1][j]);
31    }
32};
33
34class Solution {
35public:
36    int maxValidSplits(vector<int>& nums) {
37        int n = nums.size();
38
39        SparseTable st(nums);
40
41        int ans = 0;
42
43        for(int k = -1; k < n; k++){
44            int m = (k == -1) ? n : n - 1;
45
46            if(m <= 1) continue;
47
48            int tot = (k == -1) ? st.query(0, n - 1) : gcd(st.query(0, k - 1), st.query(k + 1, n - 1));
49
50            auto pref = [&](int i){
51                if(k == -1 || i < k) return st.query(0, i);
52                return gcd(st.query(0, k - 1), st.query(k + 1, i + 1));
53            };
54
55            auto suf = [&](int i){
56                if(k == -1) return st.query(i, n - 1);
57                if(i < k) return gcd(st.query(i, k - 1), st.query(k + 1, n - 1));
58                return st.query(i + 1, n - 1);
59            };
60
61            int left = m, s = 0, e = m - 2; 
62            while(s <= e){
63                int mid = s + (e - s) / 2;
64                if(pref(mid) == tot){
65                    left = mid;
66                    e = mid - 1;
67                }
68                else s = mid+ 1;
69            }
70
71            int right = -1;
72            s = 0, e = m - 2;
73            while(s <= e){
74                int mid = s + (e - s) / 2;
75                if(suf(mid + 1) == tot){
76                    right = mid;
77                    s = mid + 1;
78                    // cout << right << endl;
79                }
80                else e = mid - 1;
81            }
82
83            ans = max(ans, right - left + 1);
84        }
85        return ans;
86    }
87};
88
89
90
91
92
93
94
95
96
97
98
99
100
101
102
103
104
105
106
107
108
109