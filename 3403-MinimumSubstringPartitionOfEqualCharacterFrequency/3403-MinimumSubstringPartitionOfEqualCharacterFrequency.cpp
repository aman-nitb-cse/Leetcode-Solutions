// Last updated: 6/24/2026, 3:30:54 AM
class Solution {
public:
    map<pair<int, int>, int> B;
    bool isBalanced(unordered_map<char, int> &hash) {
        int f = hash.begin()->second;
        for (auto &i : hash) {
            if (i.second != f)
                return false;
        }
        return true;
    }
    int minimumSubstringsInPartition(string s, int i = 0, int j = -1) {
        if(j == -1) j = s.size() - 1;
        if (i > j) return 0;
        if(B.find({i, j}) != B.end()) return B[{i, j}];
        int mini = s.size(), k = i;
        unordered_map<char, int> hash;
        while (i <= j) {
            hash[s[i]]++;
            if (isBalanced(hash)) {
                mini = min(mini, minimumSubstringsInPartition(s, i + 1, j));
            }
            i++;
        }
        B[{k, j}] = mini + 1;
        return mini + 1;
    }
};
