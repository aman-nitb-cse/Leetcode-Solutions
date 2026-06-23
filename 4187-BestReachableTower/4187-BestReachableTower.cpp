// Last updated: 6/24/2026, 3:28:19 AM
class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& t, vector<int>& c, int r) {
        int maxi = -1;
        vector<int> ans = {-1, -1, -1};

        for(vector<int> &v : t){
            int d = abs(v[0] - c[0]) + abs(v[1] - c[1]);
            if(d > r) continue;
            if(maxi < v[2] || (maxi == v[2] && (v[0] < ans[0] || (v[0] == ans[0] && v[1] < ans[1])))){
                maxi = max(maxi, v[2]);
                ans = v;
            }
        }
        ans.pop_back();
        return ans;
    }
};