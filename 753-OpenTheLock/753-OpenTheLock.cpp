// Last updated: 8/20/2026, 9:00:02 PM
class Solution {
public:
    void update(char &c, int diff){
        c =  (c - '0' + 10 + diff) % 10 + '0';
    }
    int openLock(vector<string>& dead, string t) {
        
        unordered_set<string> st(dead.begin(), dead.end());

        if(st.count("0000")) return -1;
        st.insert("0000");

        queue<pair<string, int>> q; // {string, steps}

        q.push({"0000", 0});

        while(!q.empty()){
            auto [s, steps] = q.front(); q.pop();

            if(s == t) return steps;

            for(int i = 0; i < 4; i++){

                for(int diff : {1, -1}){
                    update(s[i], diff);

                    if(!st.count(s)){
                        st.insert(s);
                        q.push({s, steps + 1});
                    }

                    update(s[i], - diff);
                }
            }
        }

        return -1;
    }
};