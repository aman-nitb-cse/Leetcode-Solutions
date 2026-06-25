// Last updated: 6/25/2026, 11:37:03 PM
class Solution {
public:
    // space optimization to O(1)
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int buy = 0, sell = 0;

        for(int i = n - 1; i >= 0; i--){
            int _buy, _sell;

            // sell 
            _sell = max(
                prices[i] + buy, // sell 
                sell              // skip
            );

            // buy 
            _buy = max(
                -prices[i] - fee + sell, // buy
                buy                // skip
            );

            buy = _buy;
            sell = _sell;
        }
        return buy;
    }
};