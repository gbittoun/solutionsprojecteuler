#include <vector>

using namespace std;

#include "../Computing/FatNumber/Palindrome.hpp"

#include "problem_55.hpp"

using namespace Computing;

int problem_55()
{
    long long sum = 0;

    for(int idx = 1 ; idx < 10000 ; ++idx)
    {
        FatNumber<1024> a = idx;
        FatNumber<1024> b = MakePalindrome(a);

        bool p = true;
        for(int jdx = 0 ; jdx < 50 ; ++jdx)
        {
            cout << a << " + " << b << " = ";
            FatNumber<1024> c = (a + b);
            cout << c << endl;

            a = c;
            b = MakePalindrome(a);


            if(IsPalindrome(c))
            {
                p = false;
                break;
            }
        }

        if(p)
            ++sum;
    }

    cout << sum << endl;

    return 0;
}
