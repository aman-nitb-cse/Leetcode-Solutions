// Last updated: 8/20/2026, 9:06:19 PM
class Solution {
public:
    int countBattleships(vector<vector<char>>& b) {
        int count = 0;
        for(int i = 0; i < b.size(); i++){
            for(int j = 0; j < b[0].size(); j++){
                if(b[i][j] == '.') continue;

                if((i == 0 || b[i - 1][j] == '.') && (j == 0 || b[i][j - 1] == '.')) count++;
            }
        }
        return count;
    }
};