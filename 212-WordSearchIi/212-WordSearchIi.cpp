// Last updated: 8/20/2026, 9:11:30 PM
class node {
public:
    node* ch[26] = {nullptr};
    string end = "";

    void insert(string &s){
        auto curr = this;

        for(char &c : s){
            if(!curr->ch[c - 'a']) curr->ch[c - 'a'] = new node();
            curr = curr->ch[c - 'a'];
        }
        curr->end = s;
    }

    void search(vector<string>& ans, vector<vector<char>>& board, int i, int j){
        if(i < 0 || j < 0 || i == board.size() || j == board[0].size() || !board[i][j]) return;

        char c = board[i][j];
        int idx = c - 'a';

        if(!ch[idx]) return;

        if(!ch[idx]->end.empty()){
            ans.push_back(ch[idx]->end);
            ch[idx]->end = "";
        }

        board[i][j] = '\0';

        ch[idx]->search(ans, board, i + 1, j);
        ch[idx]->search(ans, board, i - 1, j);
        ch[idx]->search(ans, board, i, j + 1);
        ch[idx]->search(ans, board, i, j - 1);

        board[i][j] = c;
    }
};

class Solution {
public:
    node* w = new node();
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // build tries
        for(string &s : words){
            w->insert(s);
        }

        // search
        vector<string> ans;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                w->search(ans, board, i, j);
            }
        }
        return ans;
    }
};