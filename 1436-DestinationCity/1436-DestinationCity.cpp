// Last updated: 11/6/2026, 5:02:48 AM
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map <string, int> hash;
        for(int i = 0; i < paths.size(); i++){
            hash[paths[i][0]]--;
            hash[paths[i][1]]++;
        }

        for(auto &i : hash){
            if(i.second == 1) return i.first;
        }

        return "";
    }
};