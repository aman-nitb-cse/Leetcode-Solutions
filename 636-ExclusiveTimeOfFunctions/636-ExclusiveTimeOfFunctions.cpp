// Last updated: 8/20/2026, 9:02:03 PM
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n);
        stack<pair<int,int>> st, end;

        for(auto &s : logs){
            int id = stoi(s);
            int time = stoi(s.substr(s.rfind(':') + 1));

            if(s[s.find(':') + 1] == 's'){ // start
                if(!st.empty()) {
                    auto& [i, t] = st.top();
                    ans[i] += time - t;
                }
                st.push({id, time});
            }
            else { // end
                auto& [i, t] = st.top();
                if(i == id){
                    ans[i] += time - t + 1;
                    st.pop();

                    while(!end.empty() && !st.empty() && st.top().first == end.top().first){
                        st.pop();
                        end.pop();
                    }
                    if(!st.empty()){
                        auto& [i_, t_] = st.top(); st.pop();
                        st.push({i_, time + 1});
                    }
                }
                else {
                    end.push({id, time});
                }
            }
        }
        return ans;
    }
};