#include "problems/problem_77.hpp"

#include <iostream>
#include <map>
#include <vector>
#include <queue>

#include "Computing/IntegerOperations.hpp"

using namespace std;
using namespace Computing;

long long Partition(long long n)
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
            res -= ((k % 2 ? -1 : 1) * Partition(idx0));
        if(idx1 >= 0)
            res -= ((k % 2 ? -1 : 1) * Partition(idx1));

        if(idx0 < 0 && idx1 < 0)
            break;
    }

    return (p[n] = (res % 1000000LL));
}

int main()
{
    for(long long n = 10000 ; n < 1000000LL ; ++n)
    {
        long long result = Partition(n);

        cout << n << " => " << result  << endl;

        if(result == 0)
            break;
    }

    return 0;
}
