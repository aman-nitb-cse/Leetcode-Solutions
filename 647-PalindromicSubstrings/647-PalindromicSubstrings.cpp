// Last updated: 8/20/2026, 9:01:47 PM
class Solution {
public:
    int count = 0;
    vector<vector<bool>> visited;
    bool isPalindrome(string &s, int i, int j){
        while(i < j){
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }

    void solve(string &s, int i, int j){
        if(i > j) return;

        if(visited[i][j]) return;
        visited[i][j] = true;

        if(isPalindrome(s, i, j)) count++;

        solve(s, i + 1, j);
        solve(s, i, j - 1);
    }
    int countSubstrings(string s) {
        int n = s.size();
        visited.assign(n, vector<bool>(n, false));

        solve(s, 0, n - 1);
        return count;
    }
};