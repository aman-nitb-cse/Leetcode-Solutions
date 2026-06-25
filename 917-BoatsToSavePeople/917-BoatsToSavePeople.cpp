// Last updated: 6/25/2026, 11:20:12 PM
class Solution {
public:
    int numRescueBoats(vector<int>& p, int c) {
        int n = p.size();
        sort(p.begin(), p.end());
        int count = 0;
        int i = 0, j = n - 1;
        while(i < j){
            int w = p[i] + p[j];
            if(w <= c){
                count++;
                i++;
                j--;
            }
            else j--;
        }

        return n - count;
    }
};