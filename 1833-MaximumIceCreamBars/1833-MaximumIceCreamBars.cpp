// Last updated: 11/6/2026, 4:58:27 AM
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int count = 0;
        for(int &i : costs){
            if(i <= coins) count++;
            else break;
            coins -= i;
        }
        return count;
    }
};