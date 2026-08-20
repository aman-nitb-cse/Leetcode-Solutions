// Last updated: 8/20/2026, 8:57:21 PM
class Solution {
    using ll = long long;
    using Matrix = vector<vector<ll>>;
    const int mod = 1e9 + 7;

    Matrix mul(Matrix& A, Matrix& B) {
        int n = A.size();
        int m = B[0].size();
        int p = B.size();

        Matrix C(n, vector<ll>(m));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < p; k++) {
                for (int j = 0; j < m; j++) {
                    C[i][j] += A[i][k] * B[k][j];
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
    int knightDialer(int n) {
        Matrix T = {
//           0. 1. 2  3. 4. 5. 6. 7. 8. 9
            {0, 0, 0, 0, 1, 0, 1, 0, 0, 0}, // 0
            {0, 0, 0, 0, 0, 0, 1, 0, 1, 0}, // 1
            {0, 0, 0, 0, 0, 0, 0, 1, 0, 1}, // 2
            {0, 0, 0, 0, 1, 0, 0, 0, 1, 0}, // 3
            {1, 0, 0, 1, 0, 0, 0, 0, 0, 1}, // 4
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 5
            {1, 1, 0, 0, 0, 0, 0, 1, 0, 0}, // 6
            {0, 0, 1, 0, 0, 0, 1, 0, 0, 0}, // 7
            {0, 1, 0, 1, 0, 0, 0, 0, 0, 0}, // 8
            {0, 0, 1, 0, 1, 0, 0, 0, 0, 0}  // 9
        };

        Matrix M = {
            {1},
            {1},
            {1},
            {1},
            {1},
            {1},
            {1},
            {1},
            {1},
            {1},
        };

        T = power(T, n - 1);
        M = mul(T, M);

        ll ans = 0;
        for(int i = 0; i < 10; i++){
            ans += M[i][0];
            ans %= mod;
        }

        return ans;
    }
};