#include "problems/problem_2.hpp"
#include "problems/problem_3.hpp"
#include "problems/problem_4.hpp"
#include "problems/problem_7.hpp"
#include "problems/problem_9.hpp"
#include "problems/problem_10.hpp"
#include "problems/problem_11.hpp"
#include "problems/problem_12.hpp"
#include "problems/problem_13.hpp"
#include "problems/problem_14.hpp"
#include "problems/problem_15.hpp"
#include "problems/problem_16.hpp"
#include "problems/problem_17.hpp"
#include "problems/problem_18.hpp"
#include "problems/problem_19.hpp"
#include "problems/problem_20.hpp"
#include "problems/problem_21.hpp"
#include "problems/problem_22.hpp"
#include "problems/problem_23.hpp"
#include "problems/problem_24.hpp"
#include "problems/problem_25.hpp"
#include "problems/problem_26.hpp"
#include "problems/problem_27.hpp"
#include "problems/problem_28.hpp"
#include "problems/problem_29.hpp"
#include "problems/problem_30.hpp"
#include "problems/problem_31.hpp"
#include "problems/problem_32.hpp"
#include "problems/problem_33.hpp"
#include "problems/problem_34.hpp"
#include "problems/problem_35.hpp"
#include "problems/problem_36.hpp"
#include "problems/problem_37.hpp"
#include "problems/problem_38.hpp"
#include "problems/problem_40.hpp"
#include "problems/problem_41.hpp"
#include "problems/problem_42.hpp"
#include "problems/problem_43.hpp"
#include "problems/problem_44.hpp"
#include "problems/problem_45.hpp"
#include "problems/problem_46.hpp"
#include "problems/problem_47.hpp"
#include "problems/problem_48.hpp"
#include "problems/problem_49.hpp"
#include "problems/problem_50.hpp"
#include "problems/problem_51.hpp"
#include "problems/problem_52.hpp"
#include "problems/problem_54.hpp"
#include "problems/problem_55.hpp"
#include "problems/problem_56.hpp"
#include "problems/problem_57.hpp"
#include "problems/problem_58.hpp"
#include "problems/problem_59.hpp"
#include "problems/problem_60.hpp"
#include "problems/problem_76.hpp"

using namespace std;
using namespace Computing;

map<long long, map<long long, FatNumber<32> > > pascal_triangle;

FatNumber<32> Combination(long long n, long long p)
{
    if(n < p)
        return 0;

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

int main()
{
    return 0;
}
