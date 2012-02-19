#include <iostream>

#include "IntegerOperations.hpp"
#include <math.h>

namespace Computing
{
    bool ComparePair::operator()(const pair<long long, long long> & a, const pair<long long, long long> & b)
    {
        if(a.first < b.first)
            return true;
        else if(a.first > b.first)
            return false;
        else if(a.second < b.second)
            return true;

        return false;
    }

    set<int> GetDivisors(int n)
    {
        set<int> div;

        if(n <= 0)
            return div;

        div.insert(1);

        for(int idx = n/2 ; idx > 1 ; --idx)
        {
            if(n % idx == 0)
            {
                if(div.find(idx) != div.end())
                    return div;

                div.insert(idx);
                div.insert(n / idx);
            }
        }

        return div;
    }

    void FillPrimes(set<long long> & primes, long long max)
    {
        primes.clear();

        primes.insert(2);

        for(long long idx = 3 ; idx < max ; ++idx)
        {
            bool isPrime = true;

            set<long long>::iterator it = primes.begin();
            while(it != primes.end())
            {
                if(idx % *it == 0)
                {
                    isPrime = false;
                    break;
                }
                else if(*it > ceil(sqrt(idx)))
                    break;

                ++it;
            }

            if(isPrime)
                primes.insert(idx);
        }
    }

    bool IsPrime(set<long long> & p, long long n)
    {
        if(p.find(n) != p.end())
            return true;

        set<long long>::iterator it = p.begin();
        while(it != p.end())
        {
            if(n % *it == 0)
                return false;
            else if(*it > ceil(sqrt(n)))
                return true;

            ++it;
        }

        return true;
    }

    void Decompose(long long n, set<long long> & primes, map<long long, int> & pd)
    {
        set<long long>::iterator it = primes.begin();
        while(it != primes.end())
        {
            while(n % *it == 0)
            {
                ++pd[*it];
                n /= *it;
            }

            if(*it > sqrt(ceil(n)))
                break;

            ++it;
        }

        if(n > 1)
            ++pd[n];
    }

    void DumpDecomposition(map<long long, int> & pd)
    {
        map<long long, int>::iterator it = pd.begin();
        while(it != pd.end())
        {
            cout << it->first << " : " << it->second << " , ";
            ++it;
        }
        cout << endl;
    }

    long long power(long long a, long long b)
    {
        long long res = 1;
        for(long long idx = 0 ; idx < b ; ++idx)
            res *= a;

        return res;
    }

    void GetSqrtCoeff(long long n, vector<long long> & a)
    {
        float sr = sqrt(n);
        if(floor(sr) == ceil(sr))
        {
            a.push_back(floor(sr));
            return;
        }

        long long b = 0, c = 1, tmp = 0;
        set<pair<long long, long long> > mem;

        do
        {
            mem.insert(make_pair(b,c));

            do
            {
                tmp += c;
            }
            while((b - tmp - c) * (b - tmp - c) < n);

            a.push_back(tmp / c);

            b = tmp - b;
            c = (n - b * b) / c;
            tmp = 0;

        } while(mem.find(make_pair(b,c)) == mem.end());
    }

    long long Hcf(long long a, long long b)
    {
        if(a == b)
            return a;
        else if(a > b)
        {
            long long tmp = a % b;

            if(tmp == 0)
                return b;
            else
                return Hcf(tmp, b);
        }
        else
        {
            long long tmp = b % a;

            if(tmp == 0)
                return a;
            else
                return Hcf(tmp, a);
        }
    }

    long long Totient(long long n, set<long long> & primes)
    {
        map<long long, int> pd;
        Decompose(n, primes, pd);

        long long t = n;

        for(map<long long, int>::iterator it = pd.begin() ; it != pd.end() ; ++it)
        {
            t /= it->first;
            t *= it->first - 1;
        }

        return t;
    }

    long long Partition_Truncated(long long n)
    {
        static map<long long, long long> p;
        if(p.size() == 0)
            p[0] = 1;

        map<long long, long long>::iterator it = p.find(n);
        if(it != p.end())
            return it->second;

        long long res = 0;

        for(long long k = 1 ; ; ++k)
        {
            long long idx0 =  n - PolygonalNumber<5, long long>( k);
            long long idx1 =  n - PolygonalNumber<5, long long>(-k);

            if(idx0 >= 0)
                res -= ((k % 2 ? -1 : 1) * Partition_Truncated(idx0));
            if(idx1 >= 0)
                res -= ((k % 2 ? -1 : 1) * Partition_Truncated(idx1));

            if(idx0 < 0 && idx1 < 0)
                break;
        }

        return (p[n] = (res % 1000000LL));
    }
}

