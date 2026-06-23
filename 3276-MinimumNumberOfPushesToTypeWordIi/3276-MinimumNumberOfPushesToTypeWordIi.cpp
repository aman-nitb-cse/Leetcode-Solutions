// Last updated: 6/24/2026, 3:31:25 AM
class Solution {
public:
    int minimumPushes(string s) {
        vector<pair<int,char>> freq(26);
        for(char &c : s) {
            freq[c - 'a'].first++;
            freq[c - 'a'].second = c;
        }

        sort(freq.begin(), freq.end(), 
            [](auto &a, auto &b){
                return a.first > b.first;
            }
        );

        stack<pair<int,int>> st;
        st.push({4, 8});
        st.push({3, 8});
        st.push({2, 8});
        st.push({1, 8});

        vector<int> pushes(26);
        for(auto &[f, c] : freq){
            if(f == 0) break;
            if(st.top().second == 0) st.pop();

            pushes[c - 'a'] = st.top().first;
            st.top().second--;
        }

        int ans = 0;
        for(char &c : s) ans += pushes[c - 'a'];
        return ans;
    }
};