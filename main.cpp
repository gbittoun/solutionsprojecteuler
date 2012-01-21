#include "problems/problem_2.hpp"
#include "problems/problem_3.hpp"
#include "problems/problem_4.hpp"
#include "problems/problem_7.hpp"
#include "problems/problem_9.hpp"
#include "problems/problem_10.hpp"
#include "problems/problem_11.hpp"
#include "problems/problem_12.hpp"
#include "problems/problem_13.hpp"
#include "problems/problem_14.hpp"
#include "problems/problem_15.hpp"
#include "problems/problem_16.hpp"
#include "problems/problem_17.hpp"
#include "problems/problem_18.hpp"
#include "problems/problem_19.hpp"
#include "problems/problem_20.hpp"
#include "problems/problem_21.hpp"
#include "problems/problem_22.hpp"
#include "problems/problem_23.hpp"
#include "problems/problem_24.hpp"
#include "problems/problem_25.hpp"
#include "problems/problem_26.hpp"
#include "problems/problem_27.hpp"
#include "problems/problem_28.hpp"
#include "problems/problem_29.hpp"
#include "problems/problem_30.hpp"
#include "problems/problem_31.hpp"
#include "problems/problem_32.hpp"
#include "problems/problem_33.hpp"
#include "problems/problem_34.hpp"
#include "problems/problem_35.hpp"
#include "problems/problem_36.hpp"
#include "problems/problem_37.hpp"
#include "problems/problem_38.hpp"
#include "problems/problem_40.hpp"
#include "problems/problem_41.hpp"
#include "problems/problem_42.hpp"
#include "problems/problem_43.hpp"
#include "problems/problem_44.hpp"
#include "problems/problem_45.hpp"
#include "problems/problem_46.hpp"
#include "problems/problem_47.hpp"
#include "problems/problem_48.hpp"
#include "problems/problem_49.hpp"
#include "problems/problem_50.hpp"
#include "problems/problem_51.hpp"
#include "problems/problem_52.hpp"
#include "problems/problem_54.hpp"
#include "problems/problem_56.hpp"

using namespace std;
using namespace Computing;

#include <vector>

namespace Computing
{
    template<int N>
    FatNumber<N> MakePalindrome(const FatNumber<N> & x)
    {
        int limit = (sizeof(x.v) / sizeof(int)) - 1;
        int idx = 0;

        while(limit > 0 && x.v[limit] == 0)
            --limit;

        vector<char> digits;

        while(idx <= limit)
        {
            int tmp = x.v[idx++];
            if(idx == (limit+1))
            {
                while(tmp > 0)
                {
                    digits.push_back(tmp % 10);
                    tmp /= 10;
                }
            }
            else
            {
                for(int count = 0 ; count < 4 ; ++count)
                {
                    digits.push_back(tmp % 10);
                    tmp /= 10;
                }
            }
        }

        idx = 0;
        int buf = 0, count = 0, factor = 1;
        FatNumber<N> ret;

        for(vector<char>::reverse_iterator it = digits.rbegin() ; it != digits.rend() ; ++it)
        {
            buf += *it * factor;
            ++count;
            factor *= 10;

            if(count == 4)
            {
                ret.v[idx++] = buf;
                buf /= 10000;
                count = 0;
                factor = 1;
            }
        }
        ret.v[idx++] = buf;

        return ret;
    }

    template<int N>
    bool IsPalindrome(const FatNumber<N> & x)
    {
        return (x == MakePalindrome<N>(x));
    }
}

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
