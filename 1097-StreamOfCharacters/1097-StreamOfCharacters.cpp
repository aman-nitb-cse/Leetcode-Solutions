// Last updated: 6/25/2026, 11:18:42 PM
class StreamChecker {
public:
    unordered_set<string> st;
    deque<string> v;
    int n = 0;
    StreamChecker(vector<string>& w) {
        for(auto &s : w){
            st.insert(s);
            if(s.size() > n) n = s.size();
        }
    }
    
    bool query(char c) {
        v.push_back("");
        while(!v.empty() && v.front().size() >= n) v.pop_front();
        bool ans = false;
        for(auto &s : v){
            s += c;
            if(!ans) ans = st.count(s);
        }

        return ans;
    }
};