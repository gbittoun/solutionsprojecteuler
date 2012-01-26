#ifndef COMBINATION_HPP
#define COMBINATION_HPP

#include "FatNumber/FatNumber.hpp"

#include <set>
#include <map>

namespace Computing
{
    using namespace std;

    template<int N>
    FatNumber<N> Combination(long long n, long long p)
    {
        if(n < p)
            return 0;

        static map<long long, map<long long, FatNumber<N> > > pascal_triangle;

        if(pascal_triangle.size() == 0)
            pascal_triangle[0][0] = pascal_triangle[1][0] = pascal_triangle[1][1] = 1;

        map<long long, map<long long, FatNumber<32> > >::iterator it_n = pascal_triangle.find(n);
        if(it_n == pascal_triangle.end())
        {
            long long n_min = pascal_triangle.rbegin()->first + 1;

            for(long long idx = n_min ; idx <= n ; ++idx)
            {
                pascal_triangle[idx][0] = pascal_triangle[idx][idx] = 1;

                for(long long jdx = 1 ; jdx < idx ; ++jdx)
                {
                    pascal_triangle[idx][jdx] = pascal_triangle[idx-1][jdx-1] + pascal_triangle[idx-1][jdx];
                }
            }
        }

        return pascal_triangle[n][p];
    }

    void Combine(set<int> & coins, set<int>::iterator it, int val, long long & count);
}

#endif
