// Last updated: 8/20/2026, 9:16:52 PM
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int t) {
        int m = a.size(), n = a[0].size();
        int s = 0, e = m * n - 1;
        
        while(s <= e){
            int mid = s + (e - s) / 2;
            int val = a[mid / n][mid % n];
            
            if(val == t) return true;
            if(val < t) s = mid + 1;
            else e = mid - 1;
        }
        return false;
    }
};