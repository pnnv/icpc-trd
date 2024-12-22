// Theme: Matrix Opeations

template <typename T>
using row = vector<T>;
template <typename T>
using matrix = vector<vector<T>>;

// Algorithm: Matrix-Matrix Multiplication
// Complexity: O(N*K*M)

auto m_prod(matrix<int> &a, matrix<int> &b, int p = 0) {
    int n = a.size(), k = a[0].size(), m = b[0].size();

    matrix<int> res(n, row<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int z = 0; z < k; z++)
                res[i][j] = p ? (res[i][j] + a[i][z] * b[z][j] % p) % p
                : (res[i][j] + a[i][z] * b[z][j]);

    return res;
}

// Algorithm: Matrix-Vector Multiplication
// Complexity: O(N*M)

auto m_prod(matrix<int> &a, row<int> &b, int p = 0) {
    int n = a.size(), m = b.size();

    row<int> res(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res[i] = p ? (res[i] + a[i][j] * b[j] % p) % p
            : (res[i] + a[i][j] * b[j]);

    return res;
}

// Algorithm: Fast Matrix Exponentiation
// Complexity: O(N^3*log(K))

auto m_binpow(matrix<int> a, int x, int p = 0) {
    int n = a.size();

    matrix<int> res(n, row<int>(n));
    for (int i = 0; i < n; i++) res[i][i] = 1;

    while (x) {
        if (x & 1) res = m_prod(res, a, p);
        a = m_prod(a, a, p);
        x >>= 1;
    }

    return res;
}