// Last updated: 6/25/2026, 11:15:58 PM
class Solution {
public:
    bool flag(vector<int>& bd, int m, int k, int day){
        int valids = 0;
        int count = 0;
        for(int &i : bd){
            if(i <= day) count++;
            else {
                valids += count / k;
                count = 0;
            }
        }
        valids += count / k;
        return valids >= m;
    }
    int minDays(vector<int>& bd, int m, int k) {
        if(1LL * m * k > bd.size()) return -1;

        int s = ranges::min(bd);
        int e = ranges::max(bd);
        int ans = e;
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(flag(bd, m, k, mid)){
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return ans;
    }
};