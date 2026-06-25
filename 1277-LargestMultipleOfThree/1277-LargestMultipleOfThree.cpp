// Last updated: 6/25/2026, 11:17:59 PM
class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {

        // hashing + contining net remainder
        int freq[10] = {0};
        int rem = 0;
        for(int &i : digits) {
            freq[i]++;
            rem += i;
            rem %= 3;
        }

        // computing minimum elements of rem 1 & 2
        pair<int,int> rem1 = {INT_MAX, INT_MAX};
        pair<int,int> rem2 = {INT_MAX, INT_MAX};
        for(int i = 0; i < 10; i++){
            if(freq[i] == 0 || i % 3 == 0) continue;
            if(i % 3 == 1){
                rem1.first = min(rem1.first, i);
                if(rem1.first != i || freq[i] > 1) rem1.second = min(rem1.second, i);
            }
            else {
                rem2.first = min(rem2.first, i);
                if(rem2.first != i || freq[i] > 1) rem2.second = min(rem2.second, i);
            }
        }

        // remove extra elements to balance extra remainder
        if(rem == 1){
            if(rem1.first != INT_MAX) freq[rem1.first]--;
            else if(rem2.second != INT_MAX) {
                freq[rem2.first]--;
                freq[rem2.second]--;
            }
            else return "";
        }
        else if(rem == 2){
            if(rem2.first != INT_MAX) freq[rem2.first]--;
            else if(rem1.second != INT_MAX) {
                freq[rem1.first]--;
                freq[rem1.second]--;
            }
            else return "";
        }

        string s = "";
        for(int i = 9; i >= 0; i--) s += string(freq[i], i + '0');
        if(s[0] == '0') return "0";
        return s;
    }
};