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
#include "problems/problem_52.hpp"

using namespace std;
using namespace Computing;

template<int DIGITS, int BASE>
void ComputeDigitsPattern(long long n, map<char, int> & pattern)
{
    for(int idx = 0 ; idx < DIGITS ; ++idx)
    {
        pattern[idx] = n % BASE;
        n /= BASE;
    }
}

template<int DIGITS, int BASE>
void ComputeDigitsPattern(long long n, map<char, bool> & pattern)
{
    for(int idx = 0 ; idx < DIGITS ; ++idx)
    {
        pattern[idx] = (n % BASE) != 0;
        n /= BASE;
    }
}

struct DigitsPatternComparerFromBool
{
    bool operator()(const map<char, bool> & x, const map<char, bool> & y)
    {
        if(x.size() < y.size())
            return true;
        else if(x.size() > y.size())
            return false;

        map<char, bool>::const_iterator it_x = x.begin();
        map<char, bool>::const_iterator it_y = y.begin();

        while(true)
        {
            if(!it_x->second && it_y->second)
                return true;
            else if(it_x->second && !it_y->second)
                return false;

            ++it_x;
            ++it_y;
        }

        return false;
    }
};

int DigitsDiff(const map<char, int> & p0, const map<char, int> & p1)
{
    if(p0.size() >= p1.size())
    {
        int diff = p0.size();
        for(map<char, int>::const_iterator it = p0.begin() ; it != p0.end() ; ++it)
        {
            if(p1.find(it->first) != p1.end())
                --diff;
        }

        return diff;
    }
    else
    {
        int diff = p0.size();
        for(map<char, int>::const_iterator it = p1.begin() ; it != p1.end() ; ++it)
        {
            if(p0.find(it->first) != p0.end())
                --diff;
        }

        return diff;
    }

}

int main()
{
#if 0
    set<long long> primes;
    FillPrimes(primes, 1000000LL);

    for(set<long long>::iterator p0 = primes.lower_bound(10000) ; *p0 <= 100000 ; ++p0)
    {
        set<long long>::iterator p1 = p0;
        for(++p1 ; *p1 <= 100000 ; ++p1)
        {
            map<char, int> digits;
            DigitsDecompose<5, 10>(*p1 - *p0, digits);
            if(digits.size() == 2 && digits.find(0) != digits.end())
            {
                map<char, int> pattern0, pattern1, pattern2;
                DigitsDecompose<5, 10>(*p0, pattern0);
                DigitsDecompose<5, 10>(*p1, pattern1);
                DigitsDecompose<5, 10>(*p1 - *p0, pattern2);

                if(pattern0.size() == pattern1.size() && DigitsDiff(pattern0, pattern1) == 1)
                {
                    cout << *p0 << "," << *p1 << endl;
                }
            }
        }
    }

Finish:
#endif
    return 0;
}
