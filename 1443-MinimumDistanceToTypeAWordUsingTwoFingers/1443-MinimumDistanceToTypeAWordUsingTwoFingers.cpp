// Last updated: 6/25/2026, 11:17:00 PM
class Solution {
public:
    vector<vector<vector<int>>> dp;
    pair<int,int> loc(char &c){
        int d = c - 'A';
        return {d / 6, d % 6};
    }
    int dist(char a, char b){
        auto [x1, y1] = loc(a);
        auto [x2, y2] = loc(b);
        return abs(x1 - x2) + abs(y1 - y2);
    }
    int cost(string &s, char i, char j, int idx = 0){
        if(idx == s.size()) return 0; 
        auto &_dp = dp[i - 'A'][j - 'A'][idx];
        
        if(_dp == -1) 
            _dp = min(
                dist(s[idx], i) + cost(s, s[idx], j, idx + 1),
                dist(s[idx], j) + cost(s, i, s[idx], idx + 1)
            );
        return _dp;
    }
    int minimumDistance(string s) {
        dp.assign(26, vector<vector<int>> (26, vector<int> (s.size(), -1)));
        int ans = INT_MAX;
        for(char i = 'A'; i <= 'Z'; i++){
            for(char j = i + 1; j <= 'Z'; j++){
                ans = min(ans, cost(s, i, j));
            }
        }
        return ans;
    }
};