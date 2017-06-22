#include <iostream>

#include "../Computing/Combination.hpp"

using namespace Computing;
using namespace std;


template<int N>
class NumberPyramid
{
    int v[N];

    public :

    typedef struct{int a[N];} PyramidArray;

    NumberPyramid(int v_in[N])
    {
        for(size_t idx = 0 ; idx < sizeof(v) / sizeof(int) ; ++idx)
            v[idx] = v_in[idx];
    }

    PyramidArray GetCombination(long long num) const
    {
        PyramidArray ret;
        int memv[N];
        memcpy(memv, v, N * sizeof(int));

        num = num % Factorial(N);

        for(int idx = N - 1 ; idx >= 0 ; --idx)
        {
            long long div = Factorial(idx);
            int outIdx = num / div;
            num %= div;

            ret.a[N - 1 - idx] = memv[outIdx];
            for(int jdx = outIdx ; jdx < N - 1 ; ++jdx)
                memv[jdx] = memv[jdx + 1];
        }

        return ret;
    }
};

int main()
{
#if 1
    // This is the code that solves problem 24
    int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    NumberPyramid<10> test(v);

    NumberPyramid<10>::PyramidArray array = test.GetCombination(999999LL);

    for(size_t jdx = 0 ; jdx < sizeof(array.a) / sizeof(int) ; ++jdx)
        cout << array.a[jdx];

    cout << endl;
#endif

#if 0
    // This is test code to test my Pyramid number class
    int v[] = {0,1,2};
    NumberPyramid<3> test(v);

    for(int idx = 0 ; idx < 100 ; ++idx)
    {
        NumberPyramid<3>::PyramidArray array = test.GetCombination(idx);

        for(size_t jdx = 0 ; jdx < sizeof(array.a) / sizeof(int) ; ++jdx)
            cout << array.a[jdx];

        cout << endl;
    }
#endif

    return 0;
}
