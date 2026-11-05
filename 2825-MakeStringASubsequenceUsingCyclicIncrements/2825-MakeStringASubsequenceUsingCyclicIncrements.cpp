// Last updated: 11/6/2026, 4:49:36 AM
class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0;
        for(int j = 0; j < str1.size(); j++){
            if((str1[j] == 'z' and str2[i] == 'a') or str1[j] == str2[i] or str1[j] + 1 == str2[i]) i++;
        }
        return i == str2.size();
    }
};