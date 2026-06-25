// Last updated: 6/25/2026, 11:14:50 PM
class Solution {
public:
    int index(string s){
        if(s == "type") return 0;
        if(s == "color") return 1;
        return 2;
    }
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count = 0;
        int idx = index(ruleKey);
        for(int i = 0; i < items.size(); i++){
            if(items[i][idx] == ruleValue) count++;
        }
        return count;
    }
};