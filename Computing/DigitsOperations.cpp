#include "DigitsOperations.hpp"

namespace Computing
{
    void PushDigits(set<char> & s, string str)
    {
        int length = str.size();
        const char * c = str.c_str();

        for(int idx = 0 ; idx < length ; ++idx)
            s.insert(c[idx]);
    }

    bool DigitsComparer::operator()(const map<char, int> & x, const map<char, int> & y)
    {
        map<char, int>::const_iterator it_x = x.begin();
        map<char, int>::const_iterator it_y = y.begin();

        bool endx = false, endy = false;

        while(true)
        {

            if(it_x == x.end())
                endx = true;

            if(it_y == y.end())
                endy = true;

            if(endx || endy)
                break;

            if(*it_x < *it_y)
                return true;
            else if(*it_x > *it_y)
                return false;

            ++it_x;
            ++it_y;
        }

        if(endx && !endy)
            return true;

        return false;
    }


    bool PatternMatching::operator()(const map<int, bool> & x, const map<int, bool> & y)
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

    bool DigitsMatching::operator()(const map<int, int> & x, const map<int, int> & y)
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
}
