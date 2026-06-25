// Last updated: 6/25/2026, 11:20:19 PM
#define ll long long
class Solution {
public:
    int PI = 1e5;
    int NI = -1e5;
    int robotSim(vector<int>& cmd, vector<vector<int>>& ob) {
        unordered_map<int, set<ll>> x, y;
        for(auto &v : ob){
            y[v[0]].insert(v[1]);
            x[v[1]].insert(v[0]);
        }

        int r = 0, c = 0, ans = 0;
        auto store_ans = [&](){
            ans = max(ans, r * r + c * c);
        };
        string dir = "+Y";
        for(int &i : cmd){
            if(i == -1){
                if(dir == "+Y") dir = "+X";
                else if(dir == "+X") dir = "-Y";
                else if(dir == "-X") dir = "+Y";
                else dir = "-X";
            }
            else if(i == -2){
                if(dir == "+Y") dir = "-X";
                else if(dir == "+X") dir = "+Y";
                else if(dir == "-X") dir = "-Y";
                else dir = "+X";
            }
            else {
                if(dir == "+Y") {
                    auto& st = y[r];
                    if(!st.count(PI)) st.insert(PI);
                    if(!st.count(NI)) st.insert(NI);

                    int obs = *st.upper_bound(c);
                    c = min(c + i, obs - 1);
                    store_ans();
                }
                else if(dir == "+X") {
                    auto &st = x[c];
                    if(!st.count(PI)) st.insert(PI);
                    if(!st.count(NI)) st.insert(NI);

                    int obs = *st.upper_bound(r);
                    r = min(r + i, obs - 1);
                    store_ans();
                }
                else if(dir == "-X") {
                    auto &st = x[c];
                    if(!st.count(PI)) st.insert(PI);
                    if(!st.count(NI)) st.insert(NI);

                    int obs = *prev(st.lower_bound(r));
                    r = max(r - i, obs + 1);
                    store_ans();
                }
                else {
                    auto& st = y[r];
                    if(!st.count(PI)) st.insert(PI);
                    if(!st.count(NI)) st.insert(NI);

                    int obs = *prev(st.lower_bound(c));
                    c = max(c - i, obs + 1);
                    store_ans();
                }
            }
        }
        return ans;
    }
};