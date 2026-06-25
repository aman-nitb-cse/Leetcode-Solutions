// Last updated: 6/25/2026, 11:13:38 PM
class Solution {
public:
    int maxConsecutiveAnswers(string a, int k) {
        int s = 0;
        int e = 0;
        unordered_map<char,int> freq = {{'T', 0}, {'F', 0}};
        freq[a[0]]++;
        int ans = 1;
        while(e < a.size()){
            if(min(freq['T'], freq['F']) <= k){
                ans = max(ans, e - s + 1);
                e++;
                if(e < a.size()) freq[a[e]]++;
            }
            else freq[a[s++]]--;
        }
        return ans;
    }
};