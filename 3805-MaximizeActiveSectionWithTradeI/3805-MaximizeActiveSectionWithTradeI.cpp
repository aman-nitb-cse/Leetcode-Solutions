// Last updated: 8/20/2026, 8:37:23 PM
class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();

        vector<int> v;

        int cnt = 0;

        for (char& c : s) {
            if (c == '0') {
                if (cnt > 0) {
                    v.push_back(cnt);
                    cnt = 0;
                }
                cnt--;
            } else {
                if (cnt < 0) {
                    v.push_back(cnt);
                    cnt = 0;
                }
                cnt++;
            }
        }

        if (cnt)
            v.push_back(cnt);

        int sz = v.size();

        // for (int& i : v) cout << i << ' ';
        // cout << "\n\n";

        int start = 0, end = sz - 1;

        while (start < sz && v[start] > 0) start++;
        while (end >= 0 && v[end] > 0) end--;

        cnt = 0;

        for(int &i : v) if(i > 0) cnt += i;

        // cout << start << ' ' << end << endl;

        if(start >= end) return cnt;

        int i = start, j = start - 1;
        int pos_cnt = 0, sum = 0, ans = 0, pos_sum = 0;
        

        while (j <= end) {
            if (pos_cnt <= 1) {
                if (j >= 0) ans = max(ans, sum + cnt - pos_sum);
                j++;
                if (j <= end) {
                    sum += abs(v[j]);
                    if (v[j] > 0) {
                        pos_cnt++;
                        pos_sum += v[j];
                    }
                }
            } else {
                sum -= abs(v[i]);
                if (v[i] > 0) {
                    pos_cnt--;
                    pos_sum -= v[i];
                }
                i++;
            }
        }

        return ans;
    }
};