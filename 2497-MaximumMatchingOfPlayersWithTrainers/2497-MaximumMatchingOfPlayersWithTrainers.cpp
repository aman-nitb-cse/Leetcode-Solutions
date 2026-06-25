// Last updated: 6/25/2026, 11:11:40 PM
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0, count = 0;
        while(i < g.size() && j < s.size()){
            if(g[i] <= s[j]){
                count++;
                i++;
                j++;
            }
            else j++;
        }
        return count;
    }
};