// Last updated: 8/20/2026, 9:12:55 PM
class Solution {
public:
    int findMin(vector<int> v) {
        int s = 0, e = v.size() - 1;
        if(v[s] < v[e]) return v[s];
        while(s < e){
            int mid = s + (e - s) / 2;
            if(v[mid] >= v[0]) s = mid + 1;
            else e = mid;
        }
        return v[e];
    }
};