// Last updated: 7/4/2026, 8:28:30 PM
1class Solution {
2public:
3    int minOperations(string a, string b) {
4        int n = a.size();
5
6        if(n == 1 && a[0] == '1' && b[0] == '0') return -1;
7
8
9        int cnt = 0;
10        
11        for(int i = 0; i < n; i++){
12            if(a[i] == '0' && b[i] == '1'){
13                a[i] = '1';
14                cnt++;
15            }
16        }
17
18        int k = 0;
19
20        auto calc = [&](){
21            cnt += k / 2;
22            if(k & 1) cnt += 2;
23            k = 0;
24        };
25
26        for(int i = 0; i < n; i++){
27            if(a[i] == '1' && b[i] == '0'){
28                k++;
29            }
30            else calc();
31        }
32
33        calc();
34
35        return cnt;
36    }
37};