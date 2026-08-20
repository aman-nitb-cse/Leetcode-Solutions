// Last updated: 8/20/2026, 9:01:46 PM
class Trie {
public:
    Trie* arr[26] = {nullptr};
    bool end = false;

    void insert(string s) {
        auto node = this;

        for(char &c : s){
            if(node->arr[c - 'a'] == nullptr) node->arr[c - 'a'] = new Trie();
            node = node->arr[c - 'a'];
        }

        node->end = true;
    }
    
    int roots(string &s, int i){
        if(i == s.size() || s[i] == ' ' || end) return i;
        
        if(arr[s[i] - 'a']) return arr[s[i] - 'a']->roots(s, i + 1); 

        return end ? i : -1;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& d, string s) {
        // build tries
        auto node = new Trie();
        for(string &w : d) node->insert(w);
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            if(i && s[i - 1] != ' ') continue;
            int j;
            for(j = i + 1; j < s.size() && s[j] != ' '; j++); 

            int idx = node->roots(s, i);
            if(idx != -1) j = idx; 

            ans += s.substr(i, j - i) + ' ';
            i = j;
        }
        ans.pop_back();
        return ans;
    }
};