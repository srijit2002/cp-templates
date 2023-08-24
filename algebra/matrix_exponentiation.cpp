const long long MOD = 1e9 + 7;

const long long MOD2 = static_cast<long long>(MOD) * MOD;
struct Matrix {
    vector<vector<long long>> mat;
    long long n_rows, n_cols;

    Matrix() {}

    Matrix(vector<vector<long long>> values) : mat(values), n_rows(values.size()),
                                               n_cols(values[0].size()) {}

    static Matrix identity_matrix(long long n) {
        vector<vector<long long>> values(n, vector<long long>(n, 0));
        for (long long i = 0; i < n; i++)
            values[i][i] = 1;
        return values;
    }

    Matrix operator*(const Matrix &other) const {
        long long n = n_rows, m = other.n_cols;
        vector<vector<long long>> result(n_rows, vector<long long>(n_cols, 0));
        for (long long i = 0; i < n; i++)
            for (long long j = 0; j < m; j++) {
                long long tmp = 0;
                for (long long k = 0; k < n_cols; k++) {
                    tmp += mat[i][k] * 1ll * other.mat[k][j];
                    while (tmp >= MOD2)
                        tmp -= MOD2;
                }
                result[i][j] = tmp % MOD;
            }

        return move(Matrix(move(result)));
    }
    inline long long get(long long r, long long c) const {
        return mat[r][c];
    }
    inline bool is_square() const {
        return n_rows == n_cols;
    }
};
Matrix pw(Matrix a, long long p) {
    Matrix result = Matrix::identity_matrix(a.n_cols);
    while (p > 0) {
        if (p & 1)
            result = a * result;
        a = a * a;
        p >>= 1;
    }
    return result;
}