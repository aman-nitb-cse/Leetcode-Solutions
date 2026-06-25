// Last updated: 6/25/2026, 11:21:27 PM
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        auto mini = arr;
        int n = arr.size();

        for(int i = n - 2; i >= 0; i--) 
            mini[i] = min(mini[i], mini[i + 1]);
        
        int maxi = arr[0], cnt = 0;

        for(int i = 0; i < n; i++){
            maxi = max(maxi, arr[i]);

            int right_min = INT_MAX;
            if(i + 1 < n) right_min = mini[i + 1];


            if(maxi <= right_min) cnt++;
        }

        return cnt;
    }
};