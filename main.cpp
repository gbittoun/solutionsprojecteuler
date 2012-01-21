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
#include "problems/problem_56.hpp"

using namespace std;
using namespace Computing;

namespace Computing
{
    template<int N>
    FatNumber<N> MakePalindrome(const FatNumber<N> & x)
    {
        FatNumber<N> ret;

        bool startReverse = false;
        int outIdx = 0;
        for(int idx = (sizeof(x.v) / sizeof(int)) - 1 ; idx >= 0 ; --idx)
        {
            if((x.v[idx] > 0) && !startReverse)
            {
                ret.v[outIdx++] = ::MakePalindrome(x.v[idx], 10);
            }
            else if(startReverse)
            {
                ret.v[outIdx++] = ::MakePalindrome(x.v[idx], 10);
            }
        }

        return ret;
    }
}

int main()
{
    return problem_56();
}
