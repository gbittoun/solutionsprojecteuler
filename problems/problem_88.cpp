#include <iostream>
#include <map>
#include <set>
#include <vector>

#include "../Computing/IntegerOperations.hpp"

using namespace std;
using namespace Computing;

void FlattenPrimeMap(vector<long long> & primes, map<long long, int> & pd)
{
    for (map<long long, int>::iterator it = pd.begin() ; it != pd.end() ;  ++it)
    {
        for (int n = 0 ; n < it->second ; ++n)
            primes.push_back(it->first);
    }
}

void GetCombinations(set<long long> & combinations, vector<long long>::iterator current, vector<long long>::iterator end, long long n, long long result = 1)
{
    for ( ; current != end ; ++current)
    {
        if(n > 0)
            GetCombinations(combinations, current + 1, end, n-1, result**current);
        else
        {
            combinations.insert(result**current);
        }
    }
}

void GetDivisors(set<long long> & combinations, long long x, set<long long> & primes)
{
    map<long long, int> pd; // prime decomposition

    Decompose(x, primes, pd);

    vector<long long> flatPrimeSet;

    FlattenPrimeMap(flatPrimeSet, pd);

    for (int i = 0 ; i < flatPrimeSet.size() ; ++i)
    {
        GetCombinations(combinations, flatPrimeSet.begin(), flatPrimeSet.end(), i);
    }
}

long long GetNumber(vector<long long> & flatPrimeSet, long long p)
{
    vector<long long> output;

    long long tmp = 1;
    for(vector<long long>::iterator it = flatPrimeSet.begin() ; it != flatPrimeSet.end() ; ++it)
    {
        tmp *= *it;

        if(p & 0x01)
        {
            output.push_back(tmp);
            tmp = 1;
        }

        p >>= 1;
    }
    output.push_back(tmp);

    tmp = 0;
    for(vector<long long>::iterator it = output.begin() ; it != output.end() ; ++it)
    {
        tmp += *it;
    }

    return tmp;
}

long long GetNbInt(long long p)
{
    long long result = 0;

    while(p > 0)
    {
        if (p & 0x01)
            ++result;
        p >>= 1;
    }

    return result + 1;
}

int problem_88()
{
    set<long long> primes;
    FillPrimes(primes, 100000);

    map<long long, long long> result;

    set<long long> progress;
    for (long long i = 2 ; i <= 12000 ; ++i)
        progress.insert(i);

    int biggest = 0;
    long long x = 2;
    while(progress.size() > 0)
    {
        map<long long, int> pd; // prime decomposition

        Decompose(x, primes, pd);

        vector<long long> flatPrimeSet;

        FlattenPrimeMap(flatPrimeSet, pd);

        for(long long p = 1 ; p < power(2, flatPrimeSet.size() - 1) ; ++p)
        {
            long long num = GetNumber(flatPrimeSet, p);
            long long nbInt = GetNbInt(p) + (x - num);

            if(result.find(nbInt) == result.end())
            {
                result[nbInt] = x;
                progress.erase(nbInt);
            }
        }

        ++x;
    }

    set<long long> finalResult;

    for (int i = 2 ; i <= 12000 ; ++i)
    {
        finalResult.insert(result[i]);
    }

    long long sum = 0;
    for(set<long long>::iterator it = finalResult.begin() ; it != finalResult.end() ; ++it)
    {
        sum += *it;
    }

    cout << sum << endl;

    return 0;
}
