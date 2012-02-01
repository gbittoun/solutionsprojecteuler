#ifndef INTEGEROPERATIONS_HPP
#define INTEGEROPERATIONS_HPP

#include <vector>
#include <set>
#include <map>
#include <utility>

#include "FatNumber/FatNumber.hpp"

namespace Computing
{
    using namespace std;

    class ComparePair
    {
        public :

        bool operator()(const pair<long long, long long> & a, const pair<long long, long long> & b);
    };

    set<int> GetDivisors(int n);

    template<typename T>
    T GetSum(set<T> val)
    {
        T ret = 0;

        typename set<T>::iterator it = val.begin();
        for(; it != val.end() ; ++it)
        {
            ret += *it;
        }

        return ret;
    }

    void FillPrimes(set<long long> & primes, long long max);
    bool IsPrime(set<long long> & p, long long n);

    void Decompose(long long n, set<long long> & primes, map<long long, int> & pd);
    void DumpDecomposition(map<long long, int> & pd);

    template<int N, typename T>
    inline T PolygonalNumber(int n)
    {
        return n * ((N - 2) * n + (4 - N)) / 2;
    }

    long long power(long long a, long long b);
    void GetSqrtCoeff(long long n, vector<long long> & a);

    template<int N>
    struct FatFraction
    {
        FatNumber<N> u, d;
    };

    template<int N>
    FatFraction<N> DevelopSqrtCoeff(vector<long long> c, long long iterations, bool getPellsCoeff = false)
    {
        long long first = 0;

        if(getPellsCoeff)
            c.pop_back();
        else
        {
            first = c[0];
            c.erase(c.begin());
        }

        FatFraction<N> ret;
        ret.u = 0;
        ret.d = 1;

        FatNumber<N> tmp = 0;

        for(long long n = 0 ; n < iterations ; ++n)
        {
            for(vector<long long>::reverse_iterator it = c.rbegin() ; it != c.rend() ; ++it)
            {
                tmp = ret.d * *it + ret.u;
                ret.u = ret.d;
                ret.d = tmp;
            }
        }

        if(getPellsCoeff)
        {
            tmp = ret.u;
            ret.u = ret.d;
            ret.d = tmp;
        }
        else
            ret.u = ret.d * first + ret.u;

        return ret;
    }

}

#endif
