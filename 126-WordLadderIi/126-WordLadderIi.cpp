// Last updated: 8/20/2026, 9:14:08 PM
class Solution {
public:
    unordered_map<string, int> dist;
    vector<vector<string>> ans;

    void dfs(string word, string &beginWord, vector<string> &path) {
        if (word == beginWord) {
            ans.push_back(vector<string> (path.rbegin(), path.rend()));
            return;
        }

        int d = dist[word];

        for (int i = 0; i < word.size(); i++) {
            char old = word[i];

            for (char c = 'a'; c <= 'z'; c++) {
                if (c == old) continue;

                word[i] = c;

                if (dist.count(word) && dist[word] == d - 1) {
                    path.push_back(word);
                    dfs(word, beginWord, path);
                    path.pop_back();
                }
            }

            word[i] = old;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());

        if (!st.count(endWord)) return {};

        queue<string> q;
        q.push(beginWord);
        dist[beginWord] = 1;
        st.erase(beginWord);

        while (!q.empty()) {
            string s = q.front();
            q.pop();

            int d = dist[s];

            if (s == endWord)
                break;

            for (int i = 0; i < s.size(); i++) {
                char old = s[i];

                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == old)
                        continue;

                    s[i] = c;

                    if (st.count(s)) {
                        st.erase(s);
                        dist[s] = d + 1;
                        q.push(s);
                    }
                }

                s[i] = old;
            }
        }

        if (!dist.count(endWord))
            return {};

        vector<string> path = {endWord};
        dfs(endWord, beginWord, path);

        return ans;
    }
};