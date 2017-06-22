#include <iostream>

using namespace std;


bool IsEqualToFifth(int x, long long & result)
{
    int div = 1;

    while(x / div != 0)
        div *= 10;

    if(div > 1)
        div /= 10;

    long long sum = 0;
    long long current = 0;
    long long previous = x;

    while(div)
    {
        current = previous / div;
        sum += current * current * current * current * current;
        previous -= current * div;
        div /= 10;
    }

    result = sum;

    return x == sum;
}

int main()
{
    for(long long idx = 0 ; idx < 100000000LL ; ++idx)
    {
        long long res = 0;
        if(IsEqualToFifth(idx, res))
            cout << idx << " " << res << endl;
    }

    return 0;
}
