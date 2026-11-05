// Last updated: 11/6/2026, 4:32:04 AM
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans(m, string(n, '#'));
        for(char &c : ans[0]) c = '.';

        for(auto &s : ans){
            s.back() = '.';
        }
        return ans;
    }
};