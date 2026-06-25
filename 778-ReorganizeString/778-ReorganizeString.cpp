// Last updated: 6/25/2026, 11:21:31 PM
class Solution {
public:
    int prev = -1;
    char get_char(vector<int> &v){
        int maxi = (prev + 1) % (v.size());
        for(int i = 0; i < v.size(); i++){
            if(i == prev) continue;
            if(v[maxi] < v[i]) maxi = i;
        }
        if(v[maxi] == 0) return 0;
        v[maxi]--;
        prev = maxi;
        return maxi + 'a';
    }
    string reorganizeString(string s) {
        vector<int> hash(26, 0);
        int n = s.size();

        for(char &c : s) hash[c - 'a']++;

        s.clear();
        while(n--){
            char c = get_char(hash);
            if(c == 0) return "";
            s += c;
        }
        return s;
    }
};