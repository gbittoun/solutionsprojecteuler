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

int problem_88()
{
    set<long long> primes;
    FillPrimes(primes, 100000);

    long long x = 2*2*3*5*7;

    set<long long> combinations;
    GetDivisors(combinations, x, primes);

    for(set<long long>::iterator it = combinations.begin() ; it != combinations.end() ; ++it)
    {
        cout << *it << ", ";
    }
    cout << endl;

    return 0;
}
