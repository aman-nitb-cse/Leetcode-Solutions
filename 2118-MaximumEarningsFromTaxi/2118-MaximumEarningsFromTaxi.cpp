// Last updated: 6/25/2026, 11:13:42 PM
class Solution {
public:
    map<int,long long> m;
    long long after(int x){
        auto it = m.lower_bound(x);
        if(it == m.end()) return 0;
        return it->second;
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& v) {
        sort(v.begin(), v.end());

        for(int i = v.size() - 1; i >= 0; i--){
            int start = v[i][0];
            if(start >= n) continue;
            int end = min(n, v[i][1]);
            long long val = v[i][2] + end - start;

            // skip
            long long skip = after(start);
            long long take = after(end);
            m[start] = max(skip, take + val);
        }
        return m.begin()->second;
    }
};