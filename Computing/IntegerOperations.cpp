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

            if(idx % 100000 == 0)
                cout << idx << endl;
        }

        cout << "Primes computing finished !" << endl << endl;
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

    long long totient(long long n, set<long long> & primes)
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
}

