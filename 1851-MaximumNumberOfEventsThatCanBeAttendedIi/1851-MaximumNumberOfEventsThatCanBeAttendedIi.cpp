// Last updated: 6/25/2026, 11:15:01 PM
class Solution {
public:
    map<int,vector<int>> m;
    vector<int>& after(int x){
        auto it = m.upper_bound(x);
        if(it == m.end()) return m[-1];
        return it->second;
    }
    int maxValue(vector<vector<int>>& e, int k) {
        m[-1] = vector<int>(k + 1);
        sort(e.begin(), e.end());

        for(int i = e.size() - 1; i >= 0; i--){
            int &start = e[i][0];
            int &end   = e[i][1];
            int &val   = e[i][2];
            // skip 
            auto &skip = after(start);
            auto &take = after(end);

            auto &v = m[start];
            v.resize(k + 1);
            for(int j = 1; j <= k; j++){
                v[j] = max({v[j], skip[j], val + take[j - 1]});
            }
        }

        auto &v = m[e[0][0]];
        return *max_element(v.begin(), v.end());
    }
};