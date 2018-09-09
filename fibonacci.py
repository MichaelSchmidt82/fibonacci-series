import sys

def reset(memo, n):
    memo = [0 for _ in range(n)]


def fibo_recursive(n):
    if n == 0 or n == 1:
        return 1
    else:
        return fibo_recursive(n-1) + fibo_recursive(n-2)


def fibo_memorize(memo, n):

    if n <= 1:
        memo[n] = 1
        return 1

    if memo[n] == 0:
        memo[n] = fibo_memorize(memo, n-1) + fibo_memorize(memo, n-2)

    return memo[n]


def fibo_iterative(memo, n):

    if n <= 1:
        return 1

    memo[0] = 1
    memo[1] = 1

    for i in range(2, n+1, 1):
        memo[i] = memo[i-1] + memo[i-2]

    return memo[n]


def main():

    assert len(sys.argv) == 2, "Please provide N as an arguement."
    assert int(sys.argv[1]) > 0, "Arguement must be a natural number."

    n = int(sys.argv[1])
    memo = [0 for _ in range(n)]

    print("Iterative: ", fibo_iterative(memo, n-1))
    print("Dynamic:   ", fibo_memorize(memo, n-1))
    print("Recursive: ", fibo_recursive(n-1))

    return 0


if __name__ == "__main__":
    main()
