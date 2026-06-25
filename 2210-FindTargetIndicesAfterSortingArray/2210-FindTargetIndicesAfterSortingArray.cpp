// Last updated: 6/25/2026, 11:13:08 PM
class Solution {
public:
    vector<int> targetIndices(vector<int>& v, int target) {
        sort(v.begin(), v.end());
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
        vector<int> ans;
        while(first_occurance <= last_occurance && first_occurance >= 0) ans.push_back(first_occurance++);
        return ans;
    }
};