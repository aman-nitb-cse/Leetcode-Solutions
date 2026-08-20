// Last updated: 8/20/2026, 9:18:43 PM
class Solution {
public:
    vector<int> searchRange(vector<int>& v, int target) {
        int s = 0, e = v.size() - 1;
        // first occurance 
        int first_occurance = -1;
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(target == v[mid]) first_occurance = mid;
            if(target <= v[mid]) e = mid - 1;
            else s = mid + 1;
        }

        s = 0, e = v.size() - 1;
        int last_occurance = -1;
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(target == v[mid]) last_occurance = mid;
            if(target < v[mid]) e = mid - 1;
            else s = mid + 1;
        }
        return {first_occurance, last_occurance};
    }
};