// Last updated: 8/20/2026, 9:10:12 PM
class Solution {
public:
    int cal(int a, int b, char c){
        if(c == '+') return a + b;
        if(c == '-') return a - b;
        return a * b;
    }
    vector<vector<vector<int>>> dp;
    vector<int> solve(string &s, int i, int j){
        if(!dp[i][j].empty()) return dp[i][j];
        bool found = false;
        for(int k = i; k < j; k++){
            if(s[k] == '+' || s[k] == '-' || s[k] == '*'){
                auto left = solve(s, i, k - 1);
                auto right = solve(s, k + 1, j);
                for(int &x : left){
                    for(int &y : right) dp[i][j].push_back(cal(x, y, s[k]));
                }
                found = true;
            }
        }

        if(!found) dp[i][j].push_back(stoi(s.substr(i, j - i + 1)));
        return dp[i][j];
    }
    vector<int> diffWaysToCompute(string s) {
        int n = s.size();
        dp.assign(n, vector<vector<int>>(n));
        return solve(s, 0, s.size() - 1);
    }
};