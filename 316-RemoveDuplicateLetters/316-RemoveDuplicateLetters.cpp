// Last updated: 8/20/2026, 9:08:56 PM
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> idx(26);
        for(int i = 0; i < s.size(); i++){
            idx[s[i] - 'a'] = i;
        }

        bitset<26> vis;
        stack<char> st;

        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(vis[c - 'a']) continue;

            while(!st.empty() && st.top() > c && idx[st.top() - 'a'] > i){
                vis.reset(st.top() - 'a');
                st.pop();
            }

            st.push(c);
            vis.set(c - 'a');
        }

        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};