#include "problem_24.hpp"

using namespace std;

int problem_24()
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
