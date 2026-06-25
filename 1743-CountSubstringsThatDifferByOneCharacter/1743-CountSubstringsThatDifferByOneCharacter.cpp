// Last updated: 6/25/2026, 11:15:32 PM
class Trie {
public:
    Trie* c[26] = {};
    int end = 0;

    Trie(vector<string> &w){
        for(string &s : w){
            insert(s);
        }
    }

    Trie(){}
    
    // insert word
    void insert(string s) {
        auto node = this;
        for(char ch : s){
            int i = ch - 'a';
            if(!node->c[i]) node->c[i] = new Trie();
            node = node->c[i];
        }
        node->end++;
    }
    
    // count exact occurrences
    int search(string &s, int i, int j, bool canSkip = true) {
        if(i > j) return !canSkip * end;

        // match
        int cnt = c[s[i] - 'a'] ? c[s[i] - 'a']->search(s, i + 1, j, canSkip) : 0;

        // skip
        if(!canSkip) return cnt;
        for(int k = 0; k < 26; k++){
            if(c[k] && k + 'a' != s[i]) cnt += c[k]->search(s, i + 1, j, false);
        }
        return cnt;
    }
    
    // Adding a desctructor
    ~Trie() { 
        for (int i = 0; i < 26; i++) delete c[i];
    }
};

class Solution {
public:
    int countSubstrings(string s, string t) {

        Trie root;

        for(int i = 0; i < t.size(); i++){
            for(int j = i; j < t.size(); j++){
                root.insert(t.substr(i, j - i + 1));
            }
        }

        int cnt = 0;

        // substr -> strting index
        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
                cnt += root.search(s, i, j);
            }
        }

        return cnt;
    }
};