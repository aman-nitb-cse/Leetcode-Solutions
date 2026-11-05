// Last updated: 11/6/2026, 5:03:54 AM
class Solution {
public:
    string rankTeams(vector<string>& vot) {
        int n = vot.size(), size = 0;
        vector<vector<int>> v(26, vector<int> (27));
        for(string &s : vot){
            for(int i = 0; i < s.size(); i++){
                v[s[i] - 'A'][i]++;
            }
            size = max(size, (int)s.size());
        }

        for(int i = 0; i < 26; i++){
            v[i][26] = -i;
        }
        ranges::sort(v);
        string ans = "";
        for(int i = 25; i >= 0 && ans.size() < size; i--){
            ans += - v[i][26] + 'A';
        }
        return ans;
    }
};