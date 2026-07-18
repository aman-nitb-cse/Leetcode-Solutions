// Last updated: 7/18/2026, 7:00:59 PM
1class Solution {
2public:
3    using ll = long long;
4    int maximumSaleItems(vector<vector<int>>& items, int budget) {
5        int n = items.size();
6
7        vector<int> get(n + 1);
8
9        int min_price = INT_MAX;
10
11        for(auto &i : items){
12            int f = i[0], p = i[1];
13            min_price = min(min_price, p);
14
15            for(int j = 1; j * j <= f; j++){
16                if(f % j == 0){
17                    get[j]++;
18                    if(j * j != f) get[f / j]++;
19                }
20            }
21        }
22
23        priority_queue<pair<ll, ll>> pq; // {price of double product, how much available}
24
25        for(auto &i : items){
26            int free = get[i[0]] - 1, p = i[1];
27
28            if(free) pq.push({-p, free});
29        }
30
31        int count = 0, ans = budget / min_price;
32
33        while(!pq.empty()){
34            auto [p, free] = pq.top(); pq.pop();
35            p = -p;
36
37            int canTake = min(budget / p, free);
38            count += 2 * canTake;
39            budget -= canTake * p;
40
41            ans = max(ans, count + budget / min_price);
42        }
43
44        return ans;
45    }
46};