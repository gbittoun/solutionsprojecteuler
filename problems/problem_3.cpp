#include <iostream>

using namespace std;

int is_prime_number(int n)
{
    long c;

    if (n < 2) return 0;

    for (c = 2; c < n; c++)
    {
        if ((n % c) == 0) return 0;
    }

    return 1;
}

int main()
{
    long long a = 600851475143LL;
    long long b = 775147;

who_hates_goto:

    --b;
    while(a % b)
        --b;

    if(!is_prime_number(b))
        goto who_hates_goto;

    cout << a << endl;
    cout << b << endl;

    return 0;
}

