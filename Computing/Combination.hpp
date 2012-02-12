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

        typename map<long long, map<long long, FatNumber<N> > >::iterator it_n = pascal_triangle.find(n);
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

    long long Factorial(long long n);
    void Combine(set<int> & coins, set<int>::iterator it, int val, long long & count);

    template<typename T, int N>
    class ProbabilisticPyramid
    {
        T v[N];

        public :

        typedef struct{T a[N];} ProbabilisticSolution;

        ProbabilisticPyramid(T v_in[N])
        {
            for(size_t idx = 0 ; idx < N ; ++idx)
                v[idx] = v_in[idx];
        }

        ProbabilisticSolution GetCombination(long long num) const
        {
            ProbabilisticSolution ret;
            T memv[N];
            for(int idx = 0 ; idx < N ; ++idx)
                memv[idx] = v[idx];

            num = num % Factorial(N);

            for(int idx = N - 1 ; idx >= 0 ; --idx)
            {
                long long div = Factorial(idx);
                int outIdx = num / div;
                num %= div;

                ret.a[N - 1 - idx] = memv[outIdx];
                for(int jdx = outIdx ; jdx < N - 1 ; ++jdx)
                    memv[jdx] = memv[jdx + 1];
            }

            return ret;
        }

        long long GetNbCombinations()
        {
            return Factorial(N);
        }
    };
}

#endif
