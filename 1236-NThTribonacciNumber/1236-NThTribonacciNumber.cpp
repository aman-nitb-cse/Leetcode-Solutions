// Last updated: 6/25/2026, 11:18:09 PM
class Solution {
    using Matrix = vector<vector<long long>>;

    Matrix mul(Matrix& A, Matrix& B) {
        int n = A.size();
        int m = B[0].size();
        int p = B.size();

        Matrix C(n, vector<long long>(m));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < p; k++) {
                for (int j = 0; j < m; j++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        return C;
    }

    Matrix power(Matrix A, long long n) {
        int sz = A.size();

        Matrix res(sz, vector<long long>(sz));

        for (int i = 0; i < sz; i++)
            res[i][i] = 1;

        while (n) {
            if (n & 1)
                res = mul(res, A);
            A = mul(A, A);
            n >>= 1;
        }

        return res;
    }

public:
    int tribonacci(int n) {
        Matrix T = {
            {1, 1, 1},
            {1, 0, 0},
            {0, 1, 0}
        };

        Matrix _T = power(T, n);

        Matrix m = {{1}, {1}, {0}};

        Matrix M = mul(_T, m);

        return M[2][0];
    }
};