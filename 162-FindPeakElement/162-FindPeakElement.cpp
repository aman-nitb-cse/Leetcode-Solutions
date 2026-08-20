// Last updated: 8/20/2026, 9:12:42 PM
class Solution {
public:
    int findPeakElement(vector<int>& v) {
        int s = 0, e = v.size() - 1;
        while(s < e){
            int mid = s + (e - s) / 2;
            if(v[mid] < v[mid + 1]) s = mid + 1;
            else e = mid;
        }
        return s;
    }
};