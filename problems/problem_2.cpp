#include <iostream>

using namespace std;

int fibonacci_inc(int n_0, int n_1)
{
    return n_0+n_1;
}

int main()
{
    unsigned int n_0 = 1;
    unsigned int n_1 = 2;
    unsigned int sum = 2;

    while(n_1 < 4000000)
    {
        int tmp = fibonacci_inc(n_0, n_1);
        n_0 = n_1;
        n_1 = tmp;

        if((tmp % 2) == 0)
            sum += tmp;
    }

    cout << sum;

    return 0;
}
