#include "../Computing/IntegerOperations.hpp"

#include <iostream>

using namespace std;

int main()
{
    int res_a = 0,res_b = 0,highest_palindrome = 0;

    for(int a = 999, b = 999 ; (a > 100) || ( (a = 999) && (--b > 100) ) ; --a )
    {
        long long result = a * b;
        if(Computing::IsPalindrome(result, 10) && (highest_palindrome < (result)))
        {
            res_a = a;
            res_b = b;
            highest_palindrome = result;
        }
    }

    cout << res_a << " * " << res_b << " = " << highest_palindrome;

    return 0;
}
