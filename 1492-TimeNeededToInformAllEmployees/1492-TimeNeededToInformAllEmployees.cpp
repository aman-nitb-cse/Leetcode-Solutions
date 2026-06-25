// Last updated: 6/25/2026, 11:16:31 PM
class Solution {
public:
    vector<vector<int>> child;
    int solve(int id, vector<int>& t){
        if(t[id] == 0) return 0;

        int ans = 0;
        auto &v = child[id];

        for(int &i : v){
            ans = max(ans, solve(i, t));
        }
        return t[id] + ans;
    }
    int numOfMinutes(int n, int headID, vector<int>& m, vector<int>& t) {
        child.resize(n);
        for(int i = 0; i < n; i++){
            if(i != headID) child[m[i]].push_back(i);
        }
        return solve(headID, t);
    }
};