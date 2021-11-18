
// last digit of the sum of the

#include <bits/stdc++.h>
using namespace std;

// Calculate the sum of the first
// N Fibonacci numbers using Pisano
// period
long long fib(long long n)
{

    // The first two Fibonacci numbers
    long long f0 = 0;
    long long f1 = 1;

    // Base case
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    else
    {
        // Pisano period for % 10 is 60
        long long rem = n % 60;

        // Checking the remainder
        if (rem == 0)
            return 0;

        // The loop will range from 2 to
        // two terms after the remainder
        for (long long i = 2; i < rem + 3; i++)
        {
            long long f = (f0 + f1) % 60;
            f0 = f1;
            f1 = f;
        }

        long long s = f1 - 1;
        return s;
    }
}

// Driver Code
int main()
{
    long long n;
    cin >> n;
    long long final = fib(n);
    cout << final % 10 << endl;
}