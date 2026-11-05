// Last updated: 11/6/2026, 5:11:27 AM
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