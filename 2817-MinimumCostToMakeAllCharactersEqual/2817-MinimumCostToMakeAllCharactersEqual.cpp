// Last updated: 6/24/2026, 3:32:25 AM
class Solution {
public:
    int n;
    int cost(int i, int j){
        if(i == n || j == n) return 0;
        return min(j + i + 1, 2 * n - i - j - 1);
    }
    long long minimumCost(string &s) {
        n = s.size();
        int prev_one = n;
        int prev_zero = n;
        long long a1 = 0;
        long long a2 = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                prev_zero = min(prev_zero, i);
                a1 += cost(prev_one, i - 1); 
                prev_one = n;
            }
            else {
                prev_one = min(prev_one, i);
                a2 += cost(prev_zero, i - 1);
                prev_zero = n;
            }
        }

        a1 += cost(prev_one, n - 1); 
        a2 += cost(prev_zero, n - 1);

        return min(a1, a2);
    }
};