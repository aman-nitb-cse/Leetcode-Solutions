// Last updated: 8/20/2026, 9:03:05 PM
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
    int checkRecord(int n) {
        Matrix T = {
            {1,1,1,0,0,0},
            {1,0,0,0,0,0},
            {0,1,0,0,0,0},
            {1,1,1,1,1,1},
            {0,0,0,1,0,0},
            {0,0,0,0,1,0}
        };

        Matrix M = {
            {1},
            {0},
            {0},
            {0},
            {0},
            {0}
        };

        T = power(T, n);
        M = mul(T, M);

        int ans = 0;

        for(int i = 0; i < 6; i++){
            ans += M[i][0];
            ans %= mod;
        }

        return ans;
    }
};