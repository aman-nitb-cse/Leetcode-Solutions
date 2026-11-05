// Last updated: 11/6/2026, 5:03:08 AM
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        ranges::sort(words, [](auto &a, auto &b){return a.size() < b.size();});
        
        for(int i = 0; i < words.size(); i++){
            for(int j = i + 1; j < words.size(); j++){
                if(words[j].find(words[i]) != string::npos){
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};