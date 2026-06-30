// Last updated: 6/30/2026, 2:15:47 PM
class Solution {
public:
    int minCost(vector<int>& start, vector<int>& home, vector<int>& rc, vector<int>& cc) {

        int totalCost = 0;

        int row = start[0];
        int col = start[1];

        while(row < home[0]) totalCost += rc[++row];

        while(row > home[0]) totalCost += rc[--row];

        while(col < home[1]) totalCost += cc[++col];

        while(col > home[1]) totalCost += cc[--col];

        return totalCost;
    }
};