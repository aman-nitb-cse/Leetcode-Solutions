// Last updated: 8/20/2026, 9:20:38 PM
class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        if(v1.size() > v2.size()) return findMedianSortedArrays(v2, v1);

        int n1 = v1.size();
        int n2 = v2.size();
        int n = n1 + n2;

        int s = -1, e = n1 - 1;
        int i, j;

        while(true){
            i = s + (e - s) / 2;
            j = n / 2 - i - 2;

            int l1 = (i >= 0) ? v1[i] : INT_MIN;
            int r1 = (i + 1 < n1) ? v1[i+1] : INT_MAX;

            int l2 = (j >= 0) ? v2[j] : INT_MIN;
            int r2 = (j + 1 < n2) ? v2[j + 1] : INT_MAX;

            if(l1 <= r2 && l2 <= r1){
                if(n & 1) return min(r1, r2);
                return (max(l1,l2) + min(r1,r2)) / 2.0;
            }

            if(l1 > r2) e = i - 1;
            else s = i + 1;
        }
    }
};