// Last updated: 8/20/2026, 9:07:41 PM
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
        int m = a.size(), n = b.size();

        vector<vector<int>> ans;

        unordered_set<long long> vis;
        priority_queue<array<int,3>> pq;

        pq.push({-(a[0] + b[0]), 0, 0});
        vis.insert(0);

        while(k-- && !pq.empty()){
            auto [neg, i,j] = pq.top();
            pq.pop();

            ans.push_back({a[i], b[j]});

            if(i + 1 < m){
                long long key = 1LL * (i + 1) * n + j;

                if(!vis.contains(key)){
                    pq.push({-(a[i + 1] + b[j]), i + 1, j});
                    vis.insert(key);
                }
            }

            if(j + 1 < n){
                long long key = 1LL * i * n + (j + 1);

                if(!vis.contains(key)){
                    pq.push({-(a[i] + b[j + 1]), i, j + 1});
                    vis.insert(key);
                }
            }
        }

        return ans;
    }
};