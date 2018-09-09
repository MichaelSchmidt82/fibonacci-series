#include <iostream>
#include <cassert>

#include "functions.h"

using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char* argv[]) {

    assert(argc == 2 && "Please provide N as an arguement.");
    assert(atoi(argv[1]) > 0 && "Arguement must be a natural number.");

    size_t n = atoi(argv[1]);
    size_t* memo = nullptr;

    try {
        memo = new size_t[n];
    } catch (const std::bad_alloc & ba) {
        cerr << ba.what() << endl;
        return 1;
    }

    reset(memo, n);
    cout << "Iterative: " << fibo_iterative(memo, n-1) << endl;

    reset(memo, n);
    cout << "Dynamic:   " << fibo_memorize(memo, n-1) << endl;

    reset(memo, n);
    cout << "Recursive: " << fibo_recursive(n-1) << endl;

    return 0;
}
