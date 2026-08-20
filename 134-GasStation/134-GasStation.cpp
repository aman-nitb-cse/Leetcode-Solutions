// Last updated: 8/20/2026, 9:13:46 PM
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = accumulate(gas.begin(), gas.end(), 0);
        int totalCost = accumulate(cost.begin(), cost.end(), 0);

        if(totalCost > totalGas) return -1;

        int total = 0;
        int ans = 0;

        for(int i = 0; i < gas.size(); i++){
            total += gas[i] - cost[i];

            if(total < 0){
                total = 0;
                ans = i + 1;
            }
        }
        return ans;
    }
};