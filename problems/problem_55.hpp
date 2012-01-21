#include <vector>

namespace Computing
{
    using namespace std;

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

int problem_55();
