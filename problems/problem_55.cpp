#include <vector>

#include "../Computing/FatNumber/Palindrome.hpp"

using namespace Computing;
using namespace std;


int main()
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
