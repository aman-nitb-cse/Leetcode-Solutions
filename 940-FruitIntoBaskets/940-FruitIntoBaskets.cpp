// Last updated: 6/25/2026, 11:20:00 PM
class Solution {
public:
    int totalFruit(vector<int>& F) {

        int s = 0, e = -1, n = F.size(), ans = 0;

        unordered_map<int, int> freq;

        while(e < n){

            if(freq.size() > 2){
                // shrink window
                freq[F[s]]--;
                if(freq[F[s]] == 0) freq.erase(F[s]);
                s++;
            }
            else {
                ans = max(ans, e - s + 1);

                // expand window
                e++;

                if(e < n) freq[F[e]]++;
            }
        }

        return ans;
    }
};