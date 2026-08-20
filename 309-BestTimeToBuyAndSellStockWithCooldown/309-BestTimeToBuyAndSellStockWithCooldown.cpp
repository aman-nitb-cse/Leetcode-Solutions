// Last updated: 8/20/2026, 9:09:06 PM
class Solution {
public:
    // space optimization to O(1)
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int next2_buy = 0, next2_sell = 0;
        int next_buy = 0, next_sell = 0;

        for(int i = n - 1; i >= 0; i--){
            int _buy, _sell;

            // sell 
            _sell = max(
                prices[i] + next2_buy, // sell 
                next_sell              // skip
            );

            // buy 
            _buy = max(
                -prices[i] + next_sell, // buy
                next_buy                // skip
            );

            next2_buy = next_buy;
            next2_sell = next_sell;
            next_buy = _buy;
            next_sell = _sell;
        }

        return next_buy;
    }
};