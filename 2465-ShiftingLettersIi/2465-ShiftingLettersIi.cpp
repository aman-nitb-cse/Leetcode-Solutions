// Last updated: 6/25/2026, 11:11:53 PM
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> sh(n);

        for(auto& q : shifts){
            int dir = q[2] ? 1 : -1;
            sh[q[0]] += dir;
            if(q[1] < n - 1) sh[q[1] + 1] -= dir;
        }

        for(int i = 0; i < n; i++){
            if(i) sh[i] += sh[i - 1];

            s[i] = (s[i] - 'a' + sh[i] % 26 + 26) % 26 + 'a';
        }
        return s;
    }
};