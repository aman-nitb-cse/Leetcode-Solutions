// Last updated: 6/24/2026, 3:26:58 AM
class Solution {
public:
    vector<string> ans;
    string s = "";
    void dfs(int i, int n, int k){
        if(k < 0) return;
        if(i == n) {
            ans.push_back(s);
            return;
        }

        // skip
        s += '0';
        dfs(i + 1, n, k);
        s.pop_back();


        // take
        if(!s.empty() && s.back() == '1') return;
        s += '1';
        dfs(i + 1, n, k - i);
        s.pop_back();
    }
    vector<string> generateValidStrings(int n, int k) {
        dfs(0, n, k);
        return ans;
    }
};