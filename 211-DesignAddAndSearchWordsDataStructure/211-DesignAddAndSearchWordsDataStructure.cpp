// Last updated: 8/20/2026, 9:11:35 PM
class WordDictionary {
public:
    WordDictionary* arr[26] = {nullptr};
    bool end = false;
    void addWord(string s) {
        auto node = this;

        for(char &c : s){
            if(node->arr[c - 'a'] == nullptr) node->arr[c - 'a'] = new WordDictionary();
            node = node->arr[c - 'a'];
        }

        node->end = true;
    }
    
    bool search(string s, int i = 0) {
        if(i == s.size()) return end;

        if(s[i] == '.'){
            for(auto &it : arr){
                if(it && it->search(s, i + 1)) return true;
            }
            return false;
        }
        
        return arr[s[i] - 'a'] && arr[s[i] - 'a']->search(s, i + 1);
    }
};