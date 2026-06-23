// Last updated: 6/24/2026, 3:28:01 AM
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& w) {
        string ans = "";
        for(string &s : words){
            int weight = 0;
            for(char &c : s) weight += w[c - 'a'];
            weight %= 26;
            ans.push_back(25 - weight + 'a');
        }
        return ans;
    }
};