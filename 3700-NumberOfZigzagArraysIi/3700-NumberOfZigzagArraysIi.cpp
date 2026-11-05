// Last updated: 11/6/2026, 4:40:57 AM
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

    Matrix power(Matrix& A, ll n) {
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
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        Matrix M(2 * m, vector<ll> (1, 1));
        Matrix T(2 * m, vector<ll> (2 * m));

        for(int i = 0; i < m; i++){
            for(int j = m; j < m + i; j++) T[i][j] = 1;
        }

        for(int i = m; i < 2 * m; i++){
            for(int j = i - m + 1; j < m; j++) T[i][j] = 1;
        }

        T = power(T, n - 1);
        T = mul(T, M);


        ll sum = 0;

        for(int i = 0; i < 2 * m; i++){
            sum += T[i][0];
            sum %= mod;
        }

        return sum;
    }
};
