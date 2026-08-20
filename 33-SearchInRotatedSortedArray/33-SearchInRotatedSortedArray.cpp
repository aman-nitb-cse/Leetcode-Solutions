// Last updated: 8/20/2026, 9:18:52 PM
class Solution {
public:
    int getPivot(vector<int> v){
        int s = 0, e = v.size() - 1;
        if(v[e] >= v[s]) return e;
        while(s < e){
            int mid = s + (e - s) / 2;
            if(v[mid] > v[s]) s = mid;
            else if (s + 1 == e) {
                return (v[s] > v[e]) ? s : e;
            }		
            else e = mid - 1;
        }
        return s;
    }

    int search(vector<int>& v, int target) {
        int maxi = getPivot(v);
        int s = 0, e = v.size() - 1;
        if(target >= v[0]) e = maxi;
        else if(target <= v[e]) s = maxi + 1;

        while(s <= e){
            int mid = s + (e - s) / 2; 
            if(target == v[mid]) return mid;
            else if(target > v[mid]) s = mid + 1;
            else e = mid - 1;
        }
        return -1;
    }
};