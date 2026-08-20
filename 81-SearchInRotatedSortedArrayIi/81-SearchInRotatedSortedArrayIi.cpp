// Last updated: 8/20/2026, 9:16:27 PM
class Solution {
public:
    int get_pivot(vector<int> &v, int s, int e){
        if(e == s + 1){
            if(v[e] < v[s]) return s;
            return e;
        }

        if(s == e) return s;

        int mid = s + (e - s) / 2;
        if(v[mid] < v[s]) return get_pivot(v, s, mid - 1);
        return get_pivot(v, mid, e);
    }

    bool binary_search(vector<int> &v, int target, int s, int e){
        if(s > e || s < 0 || e >= v.size()) return false;
        int mid = s + (e - s) / 2;
        if(v[mid] == target) return true;
        if(v[mid] < target) return binary_search(v, target, mid + 1, e);
        return binary_search(v, target, s, mid - 1);
    }

    bool search(vector<int>& v, int target, int s = 0, int e = -2) {
        if(e == -2) e = v.size() - 1;
        if(s > e) return false;

        if(v[s] == v[e]) return target == v[s] || search(v, target, s + 1, e - 1);
        
        int pivot = get_pivot(v, s, e);
        if(target < v[s]) return binary_search(v, target, pivot + 1, e);
        return binary_search(v, target, s, pivot);
    }
};