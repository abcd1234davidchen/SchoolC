#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Iterative Fibonacci
long iterative_fib(long n)
{
    if (n <= 1)
        return n;

    long lo_fib = 0;
    long hi_fib = 1;

    for (long i = 2; i <= n; i++)
    {
        long x = lo_fib;
        lo_fib = hi_fib;
        hi_fib = x + lo_fib;
    }

    return hi_fib;
}

// Recursive Fibonacci
long recursive_fib(long n)
{
    if (n <= 1)
        return n;
    return recursive_fib(n - 1) + recursive_fib(n - 2);
}

int main()
{
    long n = 45;

    // Measuring execution time for iterative Fibonacci
    auto start_iterative = high_resolution_clock::now();
    cout << "Iterative Fibonacci of " << n << ": " << iterative_fib(n) << endl;
    auto end_iterative = high_resolution_clock::now();
    auto duration_iterative = duration_cast<microseconds>(end_iterative - start_iterative).count();
    cout << "Time taken by iterative_fib: " << duration_iterative << " microseconds" << endl;

    // Measuring execution time for recursive Fibonacci
    auto start_recursive = high_resolution_clock::now();
    cout << "Recursive Fibonacci of " << n << ": " << recursive_fib(n) << endl;
    auto end_recursive = high_resolution_clock::now();
    auto duration_recursive = duration_cast<microseconds>(end_recursive - start_recursive).count();
    cout << "Time taken by recursive_fib: " << duration_recursive << " microseconds" << endl;

    return 0;
}
