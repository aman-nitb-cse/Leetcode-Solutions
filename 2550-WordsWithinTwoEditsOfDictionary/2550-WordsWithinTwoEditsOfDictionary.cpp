// Last updated: 6/25/2026, 11:11:23 PM
class Solution {
public:
    vector<string> twoEditWords(vector<string>& q, vector<string>& D) {
        vector<string> ans;
        
        for(auto &s : q){
            for(auto &t : D){
                int diff = 0;
                for(int i = 0; i < s.size(); i++){
                    diff += (s[i] != t[i]);
                    if(diff > 2) break;
                }
                if(diff <= 2){
                    ans.push_back(s);
                    break;
                }
            }
        }
        return ans;
    }
};