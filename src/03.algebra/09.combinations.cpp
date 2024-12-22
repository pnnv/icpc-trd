// Theme: Combination Number

// Algorithm: Online Multiplication-Division
// Complexity: O(k)

// C_n^k - from n by k
int C(int n, int k) {
    int res = 1;
    
    for (int i = 1; i <= k; i++) {
        res *= n - k + i;
        res /= i;
    }
    
    return res;
}

// Algorithm: Pascal Triangle Preprocessing
// Complexity: O(N^2)

auto pascal(int n) {
    // C[i][j] = C_i+j^i
    vector<vector<int>> C(n + 1, vector<int>(n + 1, 1));
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < n + 1; j++)
            C[i][j] = C[i - 1][j] + C[i][j - 1];

    return C;
}