// Last updated: 6/25/2026, 11:10:50 PM
class Solution {
public:
    int splitNum(int num) {
        multiset<int> st;
        while (num) {
            st.insert(num % 10);
            num /= 10;
        }

        int ans = 0;
        int count = 0;

        if (st.size() & 1) {
            ans = *st.begin();
            st.erase(st.begin());
        }

        for (int i : st) {
            count++;
            if (count & 1)
                ans *= 10;
            ans += i;
        }
        return ans;
    }
};