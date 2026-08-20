// Last updated: 8/20/2026, 9:18:40 PM
class Solution {
public:
    int searchInsert(vector<int>& v, int k) {
        int n = v.size();
        int s = 0, e = n - 1;
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(k == v[mid]) return mid;
            else if(k < v[mid]) e = mid - 1;
            else s = mid + 1;
        }
        return s;
    }
};