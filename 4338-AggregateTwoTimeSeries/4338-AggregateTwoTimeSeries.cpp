// Last updated: 8/20/2026, 8:27:27 PM
class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        map<int,int> s1, s2;

        for(auto &v : series1) s1[v[0]] = v[1];
        for(auto &v : series2) s2[v[0]] = v[1];


        vector<vector<int>> ans;

        for(auto &[t, v1] : s1){
            auto it = s2.lower_bound(t);

            int v2 = (it == s2.end()) ? 0 : it->second;

            ans.push_back({t, v1 + v2});
        }

        for(auto &[t, v1] : s2){

            if(s1.count(t)) continue;
            
            auto it = s1.upper_bound(t);

            int v2 = (it == s1.end()) ? 0 : it->second;

            ans.push_back({t, v1 + v2});
        }

        ranges::sort(ans);

        return ans;
    }
};