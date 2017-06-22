#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

#include "../Computing/IntegerOperations.hpp"

using namespace std;
using namespace Computing;

void AddToMinimalProductSum(map<long long, long long> & minimalProductSum, vector<long long> & v, set<long long> * progress = 0)
{
    long long product = 1, sum = 0;

    for(vector<long long>::iterator it = v.begin() ; it != v.end() ; ++it)
    {
        product *= *it;
        sum += *it;
    }

    long long nbInt = product - sum + v.size();

    if(minimalProductSum.find(nbInt) == minimalProductSum.end())
    {
        minimalProductSum[nbInt] = product;
        if(progress)
            progress->erase(nbInt);
    }
}

class VectorComparer
{
public:
    bool operator()(const vector<long long> & v1, const vector<long long> & v2)
    {
        if(v1.size() < v2.size())
            return true;
        if(v1.size() > v2.size())
            return true;

        vector<long long>::const_iterator it1 = v1.begin(), it2 = v2.begin();

        while(it1 != v1.end())
        {
            if(*it1 < *it2)
                return true;
            if(*it1 > *it2)
                return false;

            ++it1;
            ++it2;
        }
    }
};


int main()
{
    set<long long> primes;
    FillPrimes(primes, 100000);

    map<long long, long long> minimalProductSum;

    set<long long> progress;
    for(long long i = 2 ; i <= 12000 ; ++i)
        progress.insert(i);

    long long x = 2;
    while(progress.size() > 0)
    {
        set<vector<long long>, VectorComparer > q;
        vector<long long> v;
        v.push_back(x);
        q.insert(v);

        cout << progress.size() << endl;

        while (q.size() > 0)
        {
            vector<long long> v = *q.begin();
            q.erase(q.begin());

            AddToMinimalProductSum(minimalProductSum, v, &progress);

            for(int i = 0 ; i < v.size() ; ++i)
            {
                set<long long> divisors;
                GetDivisors(divisors, v[i], primes);

                int num = divisors.size() / 2;
                for(int count = 0 ; count < num ; ++count)
                {
                    long long d = *divisors.begin();
                    divisors.erase(divisors.begin());

                    vector<long long> v_copy(v);
                    v_copy.erase(v_copy.begin() + i);

                    v_copy.push_back(d);
                    v_copy.push_back(v[i] / d);

                    sort(v_copy.begin(), v_copy.end());

                    q.insert(v_copy);
                }
            }
        }

        ++x;
    }

    long long result = 0;
    set<long long> alreadyInserted;
    for(map<long long, long long>::iterator it = minimalProductSum.begin() ; it != minimalProductSum.end() ; ++it)
    {
        cout << it->first << ": " << it->second << endl;
        if( (it-> first <= 12000) && (it-> first >= 2) && (alreadyInserted.find(it->second) == alreadyInserted.end()) )
        {
            result += it->second;
            alreadyInserted.insert(it->second);
        }
    }
    cout << result << endl;

    return 0;
}
