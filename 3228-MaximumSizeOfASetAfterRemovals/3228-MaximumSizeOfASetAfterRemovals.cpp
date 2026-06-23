// Last updated: 6/24/2026, 3:31:40 AM
class Solution {
public:
    int maximumSetSize(vector<int>& a, vector<int>& b) {
        int n = a.size();

        unordered_set<int> A(a.begin(), a.end());
        unordered_set<int> B(b.begin(), b.end());

        int common = 0;

        for(int x : A) common += B.contains(x);

        int onlyA = A.size() - common;
        int onlyB = B.size() - common;

        int takeA = min(onlyA, n / 2);
        int takeB = min(onlyB, n / 2);

        return takeA + takeB + min(common, (n / 2 - takeA) + (n / 2 - takeB));
    }
};