#ifndef INTEGEROPERATIONS_HPP
#define INTEGEROPERATIONS_HPP

#include <vector>
#include <set>
#include <map>
#include <utility>

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
}

#endif
