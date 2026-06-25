// Last updated: 6/25/2026, 11:18:20 PM
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int getTop(MountainArray &v){
        int s = 0, e = v.length() - 1;
        while(s < e){
            int mid = (s + e) / 2;
            if(v.get(mid) < v.get(mid + 1)) s = mid + 1;
            else e = mid;
        }
        return s;
    }

    int findLeft(int target, int top, MountainArray &v){
        int s = 0, e = top;
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(v.get(mid) == target) return mid;
            else if(v.get(mid) < target) s = mid + 1;
            else e = mid - 1;
        }
        return -1;
    }

    int findRight(int target, int top, MountainArray &v){
        int s = top + 1, e = v.length() - 1;
        while(s <= e){
            int mid = s + (e - s) / 2;

            if(v.get(mid) == target) return mid;
            else if(v.get(mid) < target) e = mid - 1;
            else s = mid + 1;
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &v) {
        int top = getTop(v);
        int l = findLeft(target, top, v);
        if(l != -1) return l;
        int r = findRight(target, top, v);
        if(r == -1) return -1;
        return r;
    }
};