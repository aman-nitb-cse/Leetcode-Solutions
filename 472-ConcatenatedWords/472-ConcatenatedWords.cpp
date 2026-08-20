// Last updated: 8/20/2026, 9:04:50 PM
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& w) {
        unordered_set<string> st;
        st.insert(w.begin(), w.end());
        vector<string> ans;

        for(string &s : w){
            st.erase(s);
            int n = s.size();
            vector<bool> dp(n);

            // tabulation
            for(int i = n - 1; i >= 0; i--){
                string temp = "";
                for(int j = i; j < n; j++){
                    temp += s[j];
                    if(st.count(temp) && (j == n - 1 || dp[j + 1])) {
                        dp[i] = true;
                        break;
                    }
                }
            }

            if(dp[0]) ans.push_back(s);

            st.insert(s);
        }

        return ans;
    }
};