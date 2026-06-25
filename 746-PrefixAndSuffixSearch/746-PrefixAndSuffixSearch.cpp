// Last updated: 6/25/2026, 11:21:44 PM
class WordFilter {
public:
    vector<string> w;
    WordFilter(vector<string>& words) : w(words) {}
    
    int f(string pref, string suff) {
        int m = pref.size(), n = suff.size();
        for(int i = w.size() - 1; i >= 0; i--){
            if(w[i].size() < max(m, n)) continue;
            bool valid = true;

            // pref matching
            for(int j = 0; j < m; j++){
                if(w[i][j] != pref[j]) {
                    valid = false;
                    break;
                }
            }

            if(!valid) continue;

            // suff matching
            for(int j = n - 1, k = w[i].size() - 1; j >= 0; j--, k--){
                if(w[i][k] != suff[j]){
                    valid = false;
                    break;
                }
            }

            if(!valid) continue;
            return i;
        }
        return -1;
    }
};