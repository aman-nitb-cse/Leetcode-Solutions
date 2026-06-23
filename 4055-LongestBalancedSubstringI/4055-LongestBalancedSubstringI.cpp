// Last updated: 6/24/2026, 3:29:01 AM
class Solution {
public:
    int longestBalanced(string s) {
        vector<vector<int>> v(s.size(), vector<int>(27));
        for(int i = 0; i < s.size(); i++){
            if(i) v[i] = v[i - 1];
            v[i][s[i] - 'a']++;
        }
        // padding
        v.insert(v.begin(), vector<int>(27));

        
        int ans = 1;
        for(int i = 1; i < v.size(); i++){
            for(int j = i + 1; j < v.size(); j++){
                bool isValid = true;
                int value = 0;
                for(int k = 0; k < 27; k++){
                    int dif = v[j][k] - v[i - 1][k];
                    if(dif == 0) continue;
                    if(value == 0) value = dif;
                    else if(value != dif){
                        isValid = false;
                        break;
                    }
                }

                if(isValid) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};