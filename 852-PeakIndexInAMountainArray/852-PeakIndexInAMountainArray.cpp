// Last updated: 11/6/2026, 5:12:00 AM
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& v) {
        int s = 0, e = v.size() - 1;
        while(s < e){
            int mid = s + (e - s) / 2;
            if(v[mid] < v[mid + 1]) s = mid + 1;
            else e = mid;
        }
        return s;
    }
};