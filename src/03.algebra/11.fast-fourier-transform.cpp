// Theme: Fast Fourier Transform

// Algorithm: Fast Fourier Transform (Complex)
// Complexity: O(N*log(N))

using cd = complex<double>;
const double PI = acos(-1);


auto fft(vector<cd> a, bool invert = 0) {
    // n = 2 ^ x
    int n = a.size();

    // Bit-Reversal Permutation (0000, 1000, 0100, 1100, 0010, ...)
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1) j -= bit;
        j += bit;
        if (i < j) swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        // Complex Root Of One
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd lroot(cos(ang), sin(ang));

        for (int i = 0; i < n; i += len) {
            cd root(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i + j], v = a[i + j + len / 2] * root;
                a[i + j] = (u + v);
                a[i + j + len / 2] = (u - v);
                root = (root * lroot);
            }

        }
    }

    if (invert) {
        for (int i = 0; i < n; i++) a[i] /= n;
    }

    return a;
}

// Module (7340033 = 7 * (2 ^ 20) + 1)
// Primiive Root (5 ^ (2 ^ 20) == 1 mod 7340033)
// Inverse Primitive Root (5 * 4404020 == 1 mod 7340033)
// Maximum Degree Of Two (2 ^ 20)

const int mod = 7340033;
const int proot = 5;
const int proot_1 = 4404020;                    
const int pw = 1 << 20;                                          

// Algorithm: Discrete Fourier Transform
// Complexity: O(N*log(N))

auto fft(vector<int> &a, bool invert = 0) {
    // n = 2 ^ x
    int n = a.size();

    // Bit-Reversal Permutation (0000, 1000, 0100, 1100, 0010, ...)
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1) j -= bit;
        j += bit;
        if (i < j) swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        // Current Primitive Root
        int lroot = binpow(proot, pw / len, mod);

        for (int i = 0; i < n; i += len) {
            int root = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i + j], v = a[i + j + len / 2] * root % mod;
                a[i + j] = (u + v) % mod;
                a[i + j + len / 2] = (u - v + mod) % mod;
                root = (root * lroot) % mod;
            }

        }
    }

    if (invert) {
        reverse(a.begin() + 1, a.end());
        int _n = binpow(n, mod - 2, mod);
        for (int i = 0; i < n; i++) a[i] = (a[i] * _n) % mod;
    }

    return a;
}