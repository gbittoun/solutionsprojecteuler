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

using namespace std;
using namespace Computing;

#include <sstream>

int main()
{
    set<long long> primes;
    FillPrimes(primes, 10000000);

    set<long long>::iterator it = primes.begin();

    while(it != primes.end())
    {
        ostringstream stream;
        stream << *it;
        set<int> digits;

        bool useless = false;

        for(size_t idx = 0 ; idx < stream.str().size() ; ++idx)
        {
            if(digits.find(stream.str().c_str()[idx]) != digits.end())
            {
                useless = true;
                break;
            }
            digits.insert(stream.str().c_str()[idx]);
        }

        if(useless)
        {
            ++it;
            continue;
        }

        if(*digits.begin() == '1' && digits.size() == (*digits.rbegin() - *digits.begin() + 1) )
            cout << *it << endl;

        ++it;
    }

    return 0;
}
