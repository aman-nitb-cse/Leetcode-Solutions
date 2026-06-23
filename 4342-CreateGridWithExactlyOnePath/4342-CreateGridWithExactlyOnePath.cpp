// Last updated: 6/24/2026, 3:26:22 AM
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