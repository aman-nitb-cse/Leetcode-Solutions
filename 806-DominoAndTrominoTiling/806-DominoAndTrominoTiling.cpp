// Last updated: 6/25/2026, 11:21:09 PM
class Solution {
    const int mod = 1e9 + 7;
    using ll = int;
    using Matrix = vector<vector<ll>>;

    Matrix mul(Matrix& A, Matrix& B) {
        int n = A.size();
        int m = B[0].size();
        int p = B.size();

        Matrix C(n, vector<ll>(m));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < p; k++) {
                for (int j = 0; j < m; j++) {
                    C[i][j] += (1LL * A[i][k] * B[k][j]) % mod;
                    C[i][j] %= mod;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix A, ll n) {
        int sz = A.size();

        Matrix res(sz, vector<ll>(sz));

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
    int numTilings(int n) {
        Matrix T = {
            {1, 0, 0, 1},
            {2, 1, 0, 1},
            {1, 0, 0, 0},
            {0, 1, 0, 0}
        };

        Matrix m = {
            {0},
            {1},
            {0},
            {1}
        };
        

        T = power(T, n);
        Matrix M = mul(T, m);

        return M[3][0];

    }
};