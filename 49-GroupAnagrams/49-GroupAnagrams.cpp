// Last updated: 8/20/2026, 9:18:02 PM
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        vector<vector<string>> ans;
        vector <unordered_map <char, int>> hash(s.size());
        for(int i = 0; i < s.size(); i++){
            for(char &c : s[i]) hash[i][c]++;
        }
        unordered_set <int> isVisited;
        int k = -1;
        for(int i = 0; i < hash.size(); i++){
            ans.resize(hash.size() - isVisited.size());
            if(isVisited.find(i) != isVisited.end()) continue;
            ans[++k].push_back(s[i]);
            for(int j = i + 1; j < hash.size(); j++){
                if(hash[i] == hash[j]){
                    ans[k].push_back(s[j]);
                    isVisited.insert(j);
                }
            }
        }
        return ans;
    }
};