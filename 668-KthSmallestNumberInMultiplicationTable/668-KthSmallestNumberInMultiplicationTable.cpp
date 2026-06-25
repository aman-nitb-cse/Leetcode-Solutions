// Last updated: 6/25/2026, 11:37:36 PM
class Solution {
public:
    int findKthNumber(int m, int n, int k) {

        int s = 1, e = m * n;

        while(s <= e){
            int mid = s + (e - s) / 2;

            long long cnt = 0;

            for(int i = 1; i <= m; i++)
                cnt += min(n, mid / i);

            if(cnt >= k) e = mid - 1;
            else s = mid + 1;
        }

        return s;
    }
};