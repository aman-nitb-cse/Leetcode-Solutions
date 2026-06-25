// Last updated: 6/25/2026, 11:14:37 PM
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