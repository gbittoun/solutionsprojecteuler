#include <iostream>
#include <queue>
#include <utility>
#include <vector>


int main()
{
    long long B = 1, N = 1;

    long long lastB = 1;
    long double factor = 2.0;

    while (true)
    {
        if (2 * B * B - N * N == 1)
        {
            long long b = (B + 1) / 2;
            long long n = (N + 1) / 2;

            std::cout << B << " " << N << " => " << b << " " << n ;
            if (b*b-b > 0)
                std::cout << " ==> " << ((n * n - n) / (b * b - b));
            std::cout << std::endl;

            factor = B / (double) lastB;
            lastB = B;

            B *= factor;
            N *= factor;
        }

        if (2 * B * B - N * N < 1)
            B += 1;
        else
            N += 1;
    }

    return 0;
}