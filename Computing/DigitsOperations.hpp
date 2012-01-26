#ifndef DIGITSOPERATIONS_HPP
#define DIGITSOPERATIONS_HPP

#include <string>
#include <set>
#include <map>

namespace Computing
{
    using namespace std;

    template<int BASE>
    void DigitsDecompose(long long n, map<char, int> & digits)
    {
        while(n > 0)
        {
            ++digits[n % BASE];
            n /= BASE;
        }
    }

    void PushDigits(set<char> & s, string str);

    struct DigitsComparer
    {
        bool operator()(const map<char, int> & x, const map<char, int> & y);
    };

    template<int DIGITS, int BASE>
    bool ComputeDigitsPattern(long long x, long long y, map<int, bool> & presence, map<int, int> & digits)
    {
        presence.clear();
        digits.clear();

        long long z = y - x;
        bool first = true;
        int xdigit = 0, ydigit = 0;

        for(int idx = 0 ; idx < DIGITS ; ++idx)
        {
            if(z % BASE == 0)
            {
                if(x % BASE != y % BASE)
                    goto QuickExit;

                digits[idx] = x % BASE;
            }
            else if(first)
            {
                first = false;

                xdigit = x % BASE;
                ydigit = y % BASE;
            }
            else if(x % BASE != xdigit || y % BASE != ydigit)
                goto QuickExit;

            presence[idx] = (z % BASE) == 0;

            x /= BASE;
            y /= BASE;
            z /= BASE;
        }

        return true;

    QuickExit :

        presence.clear();
        digits.clear();

        return false;
    }

    struct PatternMatching
    {
        bool operator()(const map<int, bool> & x, const map<int, bool> & y);
    };

    struct DigitsMatching
    {
        bool operator()(const map<int, int> & x, const map<int, int> & y);
    };
}

#endif
