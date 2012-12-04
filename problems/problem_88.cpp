#include <map>
#include <set>
#include <vector>

using namespace std;

void FlattenPrimeMap(vector<int> & primes, map<long long, int> & pd)
{
    for (map<long long, int>::iterator it = pd.begin() ; it != pd.end() ;  ++it)
    {
        for (int n = 0 ; n < it->second ; ++n)
            primes.push_back(it->first);
    }
}

map<int, int> GetProductSumCombinations(int x, set<long long> & primes)
{
    map<long long, int> pd; // prime decomposition

    Decompose(x, primes,  & pd);

    vector<long long> primes;

    FlattenPrimeMap(primes, pd)

    for (i = 1 ; i <= primes.size() ; ++i)
    {
        InsertCombinations()
    }

    return map<int, int>();
}


int problem_88()
{
    return 0;
}