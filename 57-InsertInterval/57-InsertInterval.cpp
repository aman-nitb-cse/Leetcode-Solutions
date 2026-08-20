// Last updated: 8/20/2026, 9:17:37 PM
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& A, vector<int>& B) {
        int s = -1, e = -1;
        int n = A.size();
        for (int i = 0; i < n; i++) {
            if (s == -1 and B[0] < A[i][0])
                s = i;
            if (B[1] > A[i][1])
                e = i;
            if (B[0] >= A[i][0] and B[0] <= A[i][1])
                s = i;
            if (B[1] >= A[i][0] and B[1] <= A[i][1])
                e = i;
        }

        if (!n) {
            A.push_back(B);
            return A;
        }

        if (s == -1 and e != -1) A.push_back(B);
        else if (s != -1 and e == -1)  A.insert(A.begin(), B);
        else if (s > e) A.insert(A.begin() + s, B);
        else {
            A[e][0] = min(A[s][0], B[0]);
            A[e][1] = max(A[e][1], B[1]);
            A.erase(A.begin() + s, A.begin() + e);
        }

        return A;
    }
};