void reset(size_t* memo, size_t n) {
    for (int i = 0; i < n; i++)
        memo[i] = 0;
}

int fibo_recursive(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return fibo_recursive(n-1) + fibo_recursive(n-2);
}

size_t fibo_memorize(size_t* memo, size_t n) {

    // Base
    if (n <= 1) {
        memo[n] = 1;
        return 1;
    }

    if (memo[n] == 0)
        memo[n] = fibo_memorize(memo, n-1) + fibo_memorize(memo, n-2);

    return memo[n];
}

size_t fibo_iterative(size_t* memo, size_t n) {

    if (n <= 1)
        return 1;

    memo[0] = 1;
    memo[1] = 1;
    for (int i = 2; i <= n; i++)
        memo[i] = memo[i-1] + memo[i-2];

    return memo[n];
}
