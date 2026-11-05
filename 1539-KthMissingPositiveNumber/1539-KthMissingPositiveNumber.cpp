// Last updated: 11/6/2026, 5:01:45 AM
class Solution {
public:
    int findKthPositive(vector<int>& v, int k) {
        int s = 0;
        int e = v.size() - 1;

        while(s <= e){
            int mid = s + (e - s) / 2;

            if(v[mid] - mid - 1 >= k) e = mid - 1;
            else s = mid + 1;
        }

        return k + e + 1;
    }
};