// Last updated: 6/25/2026, 11:13:47 PM
class Solution {
public:
    int to_num(string s) {
        int n = 0;
        for (int i = 0; i < s.size(); i++) {
            n += (s[i] - '0') * (1 << (s.size() - 1 - i));
        }
        return n;
    }

    string to_str(int n, int size) {
        string s = "";
        while (n) {
            s.insert(s.begin(), (n & 1) + '0');
            n = n >> 1;
        }

        s.insert(s.begin(), size - s.size(), '0');
        return s;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set <int> st;
        for (string& s : nums)
            st.insert(to_num(s));

        for (int i = 0; i < (1 << nums.size()); i++) {
            if (st.find(i) == st.end())
                return to_str(i, nums.size());
        }
        return "";
    }
};