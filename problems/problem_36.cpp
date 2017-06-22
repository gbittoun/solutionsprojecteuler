#include "../Computing/IntegerOperations.hpp"

#include <iostream>

using namespace std;


void DumpNumber(long long x, int base)
{
    int size = 0;
    int div = 1;

    while(x / div)
    {
        div *= base;
        ++size;
    }

    for(int idx = 0 ; idx < size ; ++idx)
    {
        cout << ((x % div) / (div / base));
        div /= base;
    }
}

int main()
{
    long long result = 0;

    for(long long idx = 0 ; idx < 1000000 ; ++idx)
    {
        if(Computing::IsPalindrome(idx, 10) && Computing::IsPalindrome(idx, 2))
        {
            DumpNumber(idx, 10);
            cout << " ";
            DumpNumber(idx, 2);
            cout << endl;

            result += idx;
        }
    }

    cout << endl << result << endl;

    return 0;
}
