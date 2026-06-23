// Last updated: 6/24/2026, 3:26:52 AM
class Solution {
public:
    bool isLower(char c){
        return c <= 'z' && c >= 'a';
    }
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& q) {
        char prev = ' ';
        string curr = "";
        unordered_map<string,int> freq;
        for(string &s : chunks){
            for(auto &c : s){
                if(prev == '-' && !isLower(c)){
                    if(!curr.empty() && curr.back() == '-') curr.pop_back();
                    freq[curr]++;
                    curr = "";
                }
                else if(c == ' '){
                    freq[curr]++;
                    curr = "";
                }
                else if(c == '-'){
                    if(!curr.empty() && isLower(curr.back())) curr += c;
                }
                else curr += c;
                prev = c;
            }
        }

        if(!curr.empty() && curr.back() == '-') curr.pop_back();
        freq[curr]++;

        vector<int> ans;
        for(auto &s : q) ans.push_back(freq[s]);
        return ans;
    }
};