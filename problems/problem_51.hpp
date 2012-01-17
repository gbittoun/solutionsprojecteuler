namespace Computing
{
    using namespace std;

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
        bool operator()(const map<int, bool> & x, const map<int, bool> & y)
        {
            if(x.size() < y.size())
                return true;
            else if(x.size() > y.size())
                return false;

            map<int, bool>::const_iterator itx = x.begin();
            map<int, bool>::const_iterator ity = y.begin();

            while(itx != x.end() && ity != y.end())
            {
                if(!itx->second && ity->second)
                    return true;
                else if(itx->second && !ity->second)
                    return false;

                ++itx;
                ++ity;
            }

            return false;
        }
    };

    struct DigitsMatching
    {
        bool operator()(const map<int, int> & x, const map<int, int> & y)
        {
            if(x.size() < y.size())
                return true;
            else if(x.size() > y.size())
                return false;

            map<int, int>::const_iterator itx = x.begin();
            map<int, int>::const_iterator ity = y.begin();

            while(itx != x.end() && ity != y.end())
            {
                if(itx->first < ity->first)
                    return true;
                else if(itx->first > ity->first)
                    return false;
                else if(itx->second < ity->second)
                    return true;
                else if(itx->second > ity->second)
                    return false;

                ++itx;
                ++ity;
            }

            return false;
        }
    };
}

int problem_51();
