// Theme: Fibonacci Sequence

// Algorithm: Fibonacci Numbers With Matrix Exponentiation
// Complexity: O(log(N))

int fibonacci(int n) {
    row<int> first_two = { 1, 0 };
    if (n <= 2) return first_two[2 - n];

    matrix<int> fib(2, row<int>(2, 0));
    fib[0][0] = 1; fib[0][1] = 1;
    fib[1][0] = 1; fib[1][1] = 0;

    fib = m_binpow(fib, n - 2);

    row<int> last_two = m_prod(fib, first_two);

    return last_two[0];
}