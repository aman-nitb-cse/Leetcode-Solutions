// Last updated: 8/20/2026, 9:13:45 PM
class Solution {
public:
    int candy(vector<int>& rat) {
        int n = rat.size();
        if(n == 1) return 1;
        vector<int> forword(n, 1);
        vector<int> backword(n, 1);

        for(int i = 1; i < n; i++){
            if(rat[i] > rat[i - 1]) forword[i] = forword[i - 1] + 1;
        }

        for(int i = n - 2; i >= 0; i--){
            if(rat[i] > rat[i + 1]) backword[i] = backword[i + 1] + 1;
        }
        int candies = 0;
        for(int i = 0; i < n; i++)
            candies += max(forword[i], backword[i]);
        
        return candies;
    }
}; 