// Last updated: 11/6/2026, 4:35:17 AM
class Solution {
public:
    int minCost(vector<int>& a, vector<int>& b) {
        int maxi = max(ranges::max(a), ranges::max(b));
        vector<int> freq_a(maxi + 1);
        vector<int> freq_b(maxi + 1);

        for(int &i : a) freq_a[i]++;
        for(int &i : b) freq_b[i]++;


        int swaps = 0;
        for(int i = 0; i <= maxi; i++){
            // failing case
            if((freq_a[i] + freq_b[i]) & 1) return -1;

            swaps += abs(freq_a[i] - freq_b[i]) / 2;

        }
        return swaps / 2;
    }
};