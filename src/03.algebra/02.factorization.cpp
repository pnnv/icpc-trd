// Theme: Factorization

// Algorithm: Trivial Algorithm
// Complexity: O(sqrt(N))

auto factors(int n) {
    vector<int> factors;

    for (int i = 2; i * i <= n; i++) {
        if (n % i) continue;
        while (n % i == 0) n /= i;
        factors.push_back(i);
    }

    if (n != 1)
        factors.push_back(n);

    return factors;
}

// Algorithm: Factorization With Sieve
// Complexity: O(N*log(log(N)))

auto factors_sieve(int n) {
    vector<int> factors,
        sieve = get_sieve(n + 1);

    while (sieve[n]) {
        factors.push_back(sieve[n]);
        n /= sieve[n];
    }

    if (n != 1)
        factors.push_back(n);

    return factors;
}

// Algorithm: Factorization With Primes
// Complexity: O(sqrt(N)/log(sqrt(N)))

auto factors_primes(int n) {
    vector<int> factors,
        primes = get_primes(n + 1);

    for (auto &i : primes) {
        if (i * i > n) break;
        if (n % i) continue;
        while (n % i == 0) n /= i;
        factors.push_back(i);
    }

    if (n != 1)
        factors.push_back(n);

    return factors;
}

// Algorithm: Ferma Test
// Complexity: O(K*log(N))

bool ferma(int n) {
    if (n == 2) return true;

    uniform_int_distribution<int> distA(2, n - 1);

    for (int i = 0; i < 1000; i++) {
        int a = distA(reng);
        if (gcd(a, n) != 1 ||
        binpow(a, n - 1, n) != 1)
            return false;
    }

    return true;
}

// Algorithm: Pollard Rho Algorithm
// Complexity: O(N^(1/4))

int f(int x, int c, int n) {
    return ((x * x) % n + c) % n;
}

int pollard_rho(int n) {
    if (n % 2 == 0) return 2;

    uniform_int_distribution<int> distC(1, n), distX(1, n);

    int c = distC(reng), x = distX(reng);
    int y = x;

    int g = 1;

    while (g == 1) {
        x = f(x, c, n);
        y = f(f(y, c, n), c, n);
        g = gcd(abs(x - y), n);
    }

    return g;
}

// Algorithm: Pollard Rho Factorization + Ferma Test
// Complexity: O(N^(1/4)*log(N))

void factors_pollard_rho(int n, vector<int> &factors) {
    if (n == 1) return;

    if (ferma(n)) {
        factors.push_back(n);
        return;
    }

    int d = pollard_rho(n);

    factors_pollard_rho(d, factors);
    factors_pollard_rho(n / d, factors);
}