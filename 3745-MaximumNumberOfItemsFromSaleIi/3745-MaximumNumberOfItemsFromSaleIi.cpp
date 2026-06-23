// Last updated: 6/24/2026, 3:30:02 AM
class Solution {
public:
    using ll = long long;
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> get(n + 1);

        int min_price = INT_MAX;

        for(auto &i : items){
            int f = i[0], p = i[1];
            min_price = min(min_price, p);

            for(int j = 1; j * j <= f; j++){
                if(f % j == 0){
                    get[j]++;
                    if(j * j != f) get[f / j]++;
                }
            }
        }

        priority_queue<pair<ll, ll>> pq; // {price of double product, how much available}

        for(auto &i : items){
            int free = get[i[0]] - 1, p = i[1];

            if(free) pq.push({-p, free});
        }

        int count = 0, ans = budget / min_price;

        while(!pq.empty()){
            auto [p, free] = pq.top(); pq.pop();
            p = -p;

            int canTake = min(budget / p, free);
            count += 2 * canTake;
            budget -= canTake * p;

            ans = max(ans, count + budget / min_price);
        }

        return ans;
    }
};