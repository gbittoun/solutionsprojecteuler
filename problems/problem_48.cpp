#include <iostream>

using namespace std;

#include "problem_48.hpp"

template<int N>
void Spread(int * x)
{
    for(int idx = 0 ; idx < N-1 ; ++idx)
    {
        x[idx+1] += x[idx] / 10;
        x[idx] %= 10;
    }
    x[N-1] = 0;
}

template<int N>
void Multiply(int * x, long long y)
{
    for(int idx = 0 ; idx < N ; ++idx)
        x[idx] *= y;

    Spread<N>(x);
}

template<int N>
void Add(int * x, int * y)
{
    for(int idx = 0 ; idx < N ; ++idx)
        x[idx] += y[idx];

    Spread<N>(x);
}

template<int N>
void DigitsDump(int x[N])
{
    for(int idx = 0 ; idx < N ; ++idx)
        cout << (int)x[N - idx - 1];
}


int problem_48()
{
    int x[] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for(int idx = 2 ; idx <= 1000 ; ++idx)
    {
        int y[] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        for(int jdx = 0 ; jdx < idx ; ++jdx)
            Multiply<11>(y, idx);

        Add<11>(x, y);

        DigitsDump<11>(x);
        cout << endl;
    }

    cout << endl;

    DigitsDump<11>(x);
    cout << endl;

    return 0;
}
