// Last updated: 11/6/2026, 5:05:58 AM
class Solution {
public:
    int after(map<int,int> &m, int k){
        auto it = m.lower_bound(k);
        return (it == m.end()) ? 0 : it->second;
    }

    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        vector<vector<int>> v;
        for(int i = 0; i < s.size(); i++) v.push_back({s[i], e[i], p[i]});
        sort(v.begin(), v.end());
        // v[i] = {start, end, profit}

        map<int,int> m;
        for(int i = v.size() - 1; i >= 0; i--){
            int &start = v[i][0];
            int &end = v[i][1];
            int &profit = v[i][2];
            int take = profit + after(m, end);
            int skip = after(m, start);
            m[start] = max({m[start], take, skip});
        }
        return m.begin()->second;
    }
};