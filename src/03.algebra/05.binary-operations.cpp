// Theme: Binary Operations

// Algorithm: Binary Multiplication
// Complexity: O(log(b))

int binmul(int a, int b, int p = 0) {
    int res = 0;
    while (b) {
        if (b & 1) res = p ? (res + a) % p : (res + a);
        a = p ? (a + a) % p : (a + a);
        b >>= 1;
    }
    return res;
}

// Algorithm: Binary Exponentiation
// Complexity: O(log(b))

int binpow(int a, int b, int p = 0) {
    int res = 1;
    while (b) {
        if (b & 1) res = p ? (res * a) % p : (res * a);
        a = p ? (a * a) % p : (a * a);
        b >>= 1;
    }
    return res;
}