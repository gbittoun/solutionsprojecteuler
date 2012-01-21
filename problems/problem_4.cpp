#include "problem_4.hpp"

#include <iostream>

using namespace std;

long long MakePalindrome(long long x, int base)
{
    long long ret = 0;

    while(x > 0)
    {
        ret *= base;
        ret += x % base;
        x /= base;
    }

    return ret;
}

int IsPalindrome(long long x, int base)
{
    return x == MakePalindrome(x, base);
}

int problem_4()
{
    int res_a,res_b,highest_palindrome = 0;

    for(int a = 999, b = 999 ; (a > 100) || ( (a = 999) && (--b > 100) ) ; --a )
    {
        long long result = a * b;
        if(IsPalindrome(result, 10) && (highest_palindrome < (result)))
        {
            res_a = a;
            res_b = b;
            highest_palindrome = result;
        }
    }

    cout << res_a << " * " << res_b << " = " << highest_palindrome;

    return 0;
}
