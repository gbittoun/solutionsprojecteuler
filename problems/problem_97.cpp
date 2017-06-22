#include <iostream>

using namespace std;


int main()
{
    long long x = 1;

    for (int n = 0 ; n < 7830457 ; ++n)
    {
        x *= 2;
        x %= 10000000000LL;
    }

    cout << ((x * 28433 + 1) % 10000000000LL) << endl;

    return 0;
}
