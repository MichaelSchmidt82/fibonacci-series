#include <iostream>
#include <cassert>

using std::cout;
using std::cerr;
using std::endl;


int fibo_recursive(int N);
int fibo_memorize(int* memo, int N);
int fibo_iterative(int* memo, int N);


int main(int argc, char* argv[]) {

    assert(argc == 2 && "Please provide N as an arguement.");
    assert(atoi(argv[1]) > 0 && "Arguement must be a natural number.");

    int N = atoi(argv[1]);
    int* memo = nullptr;

    try {
        memo = new int[N];
    } catch (const std::bad_alloc & ba) {
        cerr << ba.what() << endl;
    }

    for (int i = 0; i < N; i++)
        memo[i] = -1;
    cout << "Iterative: " << fibo_iterative(memo, N - 1) << endl;

    for (int i = 0; i < N; i++)
        memo[i] = -1;
    cout << "Dynamic:   " << fibo_memorize(memo, N - 1) << endl;


    cout << "Recursive: " << fibo_recursive(N - 1) << endl;

    return 0;
}


int fibo_recursive(int N) {
    if (N == 0 || N == 1)
        return 1;
    else
        return fibo_recursive(N - 1) + fibo_recursive(N - 2);
}

int fibo_memorize(int* memo, int N) {

    // Base
    if (N <= 1) {
        memo[N] = 1;
        return 1;
    }

    if (memo[N] == -1)
        memo[N] = fibo_memorize(memo, N - 1) + fibo_memorize(memo, N - 2);

    return memo[N];
}

int fibo_iterative(int* memo, int N) {

    if (N <= 1)
        return 1;

    memo[0] = 1;
    memo[1] = 1;
    for (int i = 2; i <= N; i++)
        memo[i] = memo[i - 1] + memo[i - 2];

    return memo[N];
}
