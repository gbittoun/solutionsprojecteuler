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
#include "problems/problem_76.hpp"

using namespace std;
using namespace Computing;

long long ConcatInt(long long p0, long long p1)
{
    long long result = 0;
    long long f = 1;

    while(p0 > 0)
    {
        result += (p0 % 10) * f;
        p0 /= 10;
        f *= 10;
    }

    while(p1 > 0)
    {
        result += (p1 % 10) * f;
        p1 /= 10;
        f *= 10;
    }

    return result;
}

int main()
{
    set<long long> primes;
    FillPrimes(primes, 1000000LL);

    set<long long>::iterator it0 = primes.begin();

    for(; *it0 < 1000 ; ++it0)
    {
        for(set<long long>::iterator it1 = primes.begin() ; *it1 < *it0 ; ++it1)
        {
            for(set<long long>::iterator it2 = primes.begin() ; *it2 < *it1 ; ++it2)
            {
                for(set<long long>::iterator it3 = primes.begin() ; *it3 < *it2 ; ++it3)
                {
                    for(set<long long>::iterator it4 = primes.begin() ; *it4 < *it3 ; ++it4)
                    {
                        long long p0 = ConcatInt(*it0, *it1);
                        long long p1 = ConcatInt(*it1, *it0);
                        long long p2 = ConcatInt(*it0, *it2);
                        long long p3 = ConcatInt(*it2, *it0);
                        long long p4 = ConcatInt(*it1, *it2);
                        long long p5 = ConcatInt(*it1, *it2);
                        long long p6 = ConcatInt(*it0, *it3);
                        long long p7 = ConcatInt(*it3, *it0);
                        long long p8 = ConcatInt(*it1, *it3);
                        long long p9 = ConcatInt(*it3, *it1);
                        long long p10 = ConcatInt(*it2, *it3);
                        long long p11 = ConcatInt(*it3, *it2);
                        long long p12 = ConcatInt(*it0, *it4);
                        long long p13 = ConcatInt(*it4, *it2);

                        if(
                           primes.find(p0) != primes.end() &&
                           primes.find(p1) != primes.end() &&
                           primes.find(p2) != primes.end() &&
                           primes.find(p3) != primes.end() &&
                           primes.find(p4) != primes.end() &&
                           primes.find(p5) != primes.end() &&
                           primes.find(p6) != primes.end() &&
                           primes.find(p7) != primes.end() &&
                           primes.find(p8) != primes.end() &&
                           primes.find(p9) != primes.end() &&
                           primes.find(p10) != primes.end() &&
                           primes.find(p11) != primes.end() &&
                           primes.find(p12) != primes.end() &&
                           primes.find(p13) != primes.end()
                           )
                            cout << *it0 << "," << *it1 << "," << *it2 << "," << *it3 << "," << *it4 << endl;
                    }
                }
            }
        }
    }

    return 0;
}
