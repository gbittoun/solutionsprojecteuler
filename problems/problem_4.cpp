#include "problem_4.hpp"

#include <iostream>

using namespace std;

int is_palindrome(int x)
{
    int num[16];
    int size = 0;
    int div = 1;

    while(x / div)
    {
        div *= 10;
        ++size;
    }

    for(int idx = 0 ; idx < size ; ++idx)
    {
        num[idx] = (x % div) / (div / 10);
        div /= 10;
    }

    for(int idx = 0 ; idx < size / 2; ++idx)
    {
        if(num[idx] != num[size - idx - 1])
            return 0;
    }

    return 1;
}

int problem_4()
{
    int res_a,res_b,highest_palindrome = 0;

    for(int a = 999, b = 999 ; (a > 100) || ( (a = 999) && (--b > 100) ) ; --a )
    {
        int result = a * b;
        if(is_palindrome(result) && (highest_palindrome < (result)))
        {
            res_a = a;
            res_b = b;
            highest_palindrome = result;
        }
    }

    cout << res_a << " * " << res_b << " = " << highest_palindrome;

    return 0;
}
